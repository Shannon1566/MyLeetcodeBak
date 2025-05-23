#!/bin/bash

# 获取当前日期，格式为 "YYYY MM DD"
DATE=$(date "+%Y %m %d")

# 移动除 0.cpp 外的所有 .cpp 文件到 ./old，并记录日志
for file in ./*.cpp; do
    if [[ "$(basename "$file")" != "0.cpp" ]]; then
        mv "$file" ./old/
        echo "$DATE $(basename "$file")" >> ./study.log
    fi
done

# 删除当前目录下的所有 .exe 文件
find . -maxdepth 1 -type f -name "*.exe" -delete

# 添加所有更改
git add .

# 提交更改，附带日期作为 commit message
git commit -m "$DATE"

# 推送到两个远程仓库：origin 和 github
git push origin master
git push github master
