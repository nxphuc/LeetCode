# Python script to generate source code file for a given leetcode problem url

import os
import argparse
import re
import requests
import json
from bs4 import BeautifulSoup

BASE_URL = 'https://leetcode.com'
GRAPHQL_URL = f'{BASE_URL}/graphql'
PROBLEMS_URL = f'{BASE_URL}/problems'
BASE_QUERY = '\n'.join([
    'query getQuestionDetail($titleSlug: String!) {',
    '    question(titleSlug: $titleSlug) {',
    '        questionId',
    '        questionFrontendId',
    '        judgerAvailable',
    '        judgeType',
    '        mysqlSchemas',
    '        title',
    '        titleSlug',
    '        content',
    '        difficulty',
    '        exampleTestcases',
    '        topicTags {',
    '            name',
    '            slug',
    '        }',
    '        codeSnippets {',
    '            lang',
    '            langSlug',
    '            code',
    '        }',
    '        metaData',
    '    }',
    '}'
])

LANGUAGE_CHOICES = {
    "cpp": "cpp",
    "py": "python3",
    "java": "java",
    'ts': 'ts',
    'js': 'js'
}

def parse_args():
    parser = argparse.ArgumentParser(
        description='Leetcode solution file generator',
        formatter_class=argparse.RawTextHelpFormatter
    )
    parser.add_argument('--language', '-l',
                        metavar='language',
                        nargs='?',
                        default='cpp',
                        dest='language',
                        choices=LANGUAGE_CHOICES.keys(),
                        help='Language to be used: C++/Python/Java/TypeScript/JavaScript')
    parser.add_argument('url',
                        nargs='?',
                        help='LeetCode problem\'s URL')
    return parser.parse_args()


def stringify(content, language):
    content = content.replace('<sup>', '^').replace('</sup>', '')
    soup = BeautifulSoup(content, features="html.parser")
    for ele in soup.find_all('li'):
        ele.string = '- ' + ele.get_text()
    content = soup.get_text().replace('\n\n', '\n').strip().split('\n')
    line_comment = '# ' if language in ['py', 'shell', 'sql'] else ' * '
    content = [line_comment + line for line in content]
    if line_comment != '# ':
        content.insert(0, '/**')
        content.append('**/')
    return content


def fetch_problem(url):
    if not url:
        print(f"Invalid url, expected '{PROBLEMS_URL}/<problem_name>")
        exit(0)

    match = re.match(f'^{PROBLEMS_URL}\/[a-zA-Z0-9\-]+\/?$', url, re.IGNORECASE)
    if not match:
        print(f"Invalid url, expected '{PROBLEMS_URL}/<problem_name>")
        exit(0)
    title_slug = url.strip('/').split('/')[-1]

    headers = {
        'authority': 'leetcode.com',
        'accept': '*/*',
        'accept-language': 'en-US,en;q=0.9,vi-VN;q=0.8,vi;q=0.7',
        'content-type': 'application/json',
        'cookie': '_ga_DKXQ03QCVK=GS1.1.1676034558.1.1.1676034576.42.0.0; csrftoken=zunSg527qaFxkHn5sVHNB4zzv8YWFBU8Kkt1Yg4W0YifIJwOI6Y3MQJ4Xidk91tp; _gid=GA1.2.256485165.1687398858;',
        'origin': 'https://leetcode.com',
        'pragma': 'no-cache',
        'x-csrftoken': 'zunSg527qaFxkHn5sVHNB4zzv8YWFBU8Kkt1Yg4W0YifIJwOI6Y3MQJ4Xidk91tp',
        'referer': url,
    }

    query = {
        'variables': {
            'titleSlug': title_slug,
        },
        'query': BASE_QUERY,
        'operationName': 'getQuestionDetail'
    }

    res = requests.post(GRAPHQL_URL, headers=headers, json=query)
    
    if res.status_code != 200:
        res.raise_for_status()
    return res.json()['data']['question']


def getTag(tag):
    return tag['name']


def generate_source_file(problem, category, language):
    problemTags = map(getTag, problem["topicTags"])

    headers = [
        f'Title: {problem["title"]}',
        f'Source: {PROBLEMS_URL}/{problem["titleSlug"]}',
        f'Difficulty: {problem["difficulty"]}',
        f'Tags: {", ".join(problemTags)}',
        f'Author: nxphuc',
        f'Time Complexity: ',
        f'Space Complexity: ',
        f'Note: '
    ]
    line_comment = '#' if language in ['py', 'shell', 'sql'] else '//'

    headers = [line_comment + ' ' + header for header in headers]
    statement = stringify(problem["content"], language)

    code_snippet = [snippet["code"] for snippet in problem["codeSnippets"] if snippet["langSlug"] == LANGUAGE_CHOICES.get(language)]
    if language == 'cpp':
        code_snippet.insert(0, '#include <bits/stdc++.h>\nusing namespace std;\n')
    file_name = f'{problem["questionId"]:>04}-{problem["titleSlug"]}.{language}'

    if not os.path.exists(category):
        os.makedirs(category)
    with open(f'{category}/{file_name}', 'w', newline='\n', encoding='utf-8') as f:
        f.write('\n'.join(headers))
        f.write('\n\n')
        f.write('\n'.join(statement))
        f.write('\n\n')
        f.write('\n'.join(code_snippet))


def get_problem_category(problem):
    metadata = json.loads(problem['metaData'])

    if metadata.get('shell'):
        return 'shell'
    if metadata.get('database'):
        return 'database'
    languages = metadata.get('languages')
    if languages and len(languages) == 2 and 'javascript' in languages and 'typescript' in languages:
        return 'javascript'
    return 'algorithms'


def main():
    args = parse_args()
    problem = fetch_problem(args.url)
    category = get_problem_category(problem)
    language = args.language
    if category == 'shell':
        language = 'sh'
    elif category == 'database':
        language = 'sql'
    elif category == 'javascript':
        if language not in ['js', 'ts']:
            print(f'Problem "{problem["questionId"]} - {problem["title"]}" only support JavaScript (js) and TypeScript (ts)')
            return

    generate_source_file(problem, category, language)


if __name__ == '__main__':
    main()