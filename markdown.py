import os

TABLE_HEADER = [
    "| # | Title | Solution | Time | Space | Difficulty | Tag | Topic |",
    "|---|------ | -------- | ---- | ----- | ---------- |---- | ----- |"
]

TEMPLATE = [
    "# LeetCode Solutions",
    "",
    "Author: [nxphuc](https://github.com/nxphuc)",
    "",
    "My solution for LeetCode's problems",
    "",
    "Note: Space complexity is extra space",
    "",
    "----------------------------",
]

LANG_DICT = {
    'cpp': 'C++',
    'py': 'Python',
    'java': 'Java',
    'sh': 'Shell',
    'sql': 'MySQL',
    'js': 'JavaScript',
    'ts': 'TypeScript'
}

def gen_markdown_line(filename):
    metadata = []
    with open(filename, 'r') as f:
        for _ in range(8):
            line = f.readline()
            metadata.append(line[line.index(':') + 2:].strip())
    id = filename.split('-')[0][-4:]
    language = LANG_DICT.get(filename.split('.')[-1])
    [title, url, difficulty, tags, _, time, space, topic] = metadata
    s = f'| {id} | [{title}]({url}) | [{language}](./solutions/{filename}) |'
    s += f' _{time}_ |' if len(time) > 0 else ' |'
    s += f' _{space}_ |' if len(space) > 0 else ' |'
    return s + f' {difficulty} | {tags} | {topic} |'


def generate_category_table(dir):
    markdown = TABLE_HEADER.copy()
    solutions = os.listdir(dir)
    for sol in solutions:
        markdown.append(gen_markdown_line(f'{dir}/{sol}'))
    markdown.extend([
        '<br/>',
        '   <div align="right">',
        '       <b><a href="#leetcode-solutions">▲ Back to Top</a></b>',
        '   </div>',
        '<br/>'
    ])
    return markdown

def main():
    markdown = TEMPLATE

    list_dir = os.listdir('./')
    for dir in list_dir:
        if not os.path.isdir(dir) or dir[0] == '.':
            continue
        markdown.extend(['', f'## {dir.capitalize()}', ''])
        markdown.extend(generate_category_table('./' + dir))

    with open('README.md', 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(markdown))

if __name__ == '__main__':
    main()
