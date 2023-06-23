import os

TEMPLATE = [
    "# LeetCode Solutions",
    "",
    "Author: [github.com/nxphuc](https://github.com/nxphuc)",
    "",
    "My solution for LeetCode's problems",
    "",
    "| # | Title | Solution | Time | Space | Difficulty | Tag | Topic |",
    "|---|------ | -------- | ---- | ----- | ---------- |---- | ----- |"
]

LANG_DICT = {
    'cpp': 'C++',
    'py': 'Python',
    'java': 'Java'
}

def gen_markdown_line(filename):
    metadata = []
    with open(f'solutions/{filename}', 'r') as f:
        for _ in range(8):
            line = f.readline()
            metadata.append(line[line.index(':') + 2:].strip())
    id = filename.split('-')[0]
    language = LANG_DICT.get(filename.split('.')[-1])
    [title, url, difficulty, tags, _, time, space, topic] = metadata
    return f'| {id} | [{title}]({url}) | [{language}](./solutions/{filename}) | {time} | {space} | {difficulty} | {tags} | {topic} |'


def main():
    solutions = os.listdir('solutions/')
    markdown = TEMPLATE
    for sol in solutions:
        markdown.append(gen_markdown_line(sol))
    
    with open('README.md', 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(markdown))


if __name__ == '__main__':
    main()
