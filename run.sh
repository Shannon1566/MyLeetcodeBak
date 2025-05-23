#!/bin/bash

# 检查是否传入了参数
if [ $# -lt 1 ]; then
  echo "用法: $0 <cpp文件>"
  exit 1
fi

cpp_file="$1"

# 检查文件是否存在
if [ ! -f "$cpp_file" ]; then
  echo "错误: 文件 '$cpp_file' 不存在"
  exit 1
fi

# 获取文件名（去掉路径和扩展名）
filename=$(basename "$cpp_file" .cpp)

# 编译
g++ "$cpp_file" -o "$filename"
if [ $? -ne 0 ]; then
  echo "编译失败"
  exit 1
fi

# 运行
echo "运行 $cpp_file"
./"$filename"
rm ./"$filename"

