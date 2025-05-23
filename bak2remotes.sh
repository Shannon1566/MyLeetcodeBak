#!/bin/bash

# 获取当前日期，格式为 "YYYY MM DD"
DATE=$(date "+%Y %m %d")

# 创建临时日志内容
LOG_TEMP=""

# 移动除 0.cpp 外的所有 .cpp 文件到 ./old，并记录日志内容
for file in ./*.cpp; do
    if [[ "$(basename "$file")" != "0.cpp" ]]; then
        mv "$file" ./old/
        LOG_TEMP+="$DATE $(basename "$file")"$'\n'
    fi
done

# 如果有日志内容，则插入到 study.log 文件头部
if [[ -n "$LOG_TEMP" ]]; then
    {
        echo -n "$LOG_TEMP"
        cat ./study.log 2>/dev/null
    } > ./study.log.tmp && mv ./study.log.tmp ./study.log
fi

# 添加所有更改
git add .

# 提交更改，附带日期作为 commit message
git commit -m "$DATE"

# 推送到两个远程仓库：origin 和 github
git push origin master
git push github master
