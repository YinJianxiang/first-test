#!/bin/bash

#定义
a=(1 2 3 4 5)

###获取###
echo "获得"
a=(1 2 3 4 5)


#长度
echo ${#a[@]}
echo ${#a[*]}

#指定下标
echo ${a[2]}

#数组的整个内容
echo ${a[@]}
echo ${a[*]}

###赋值###
echo "赋值"
a=(1 2 3 4 5)

#直接操作
a[1]=1000
#如果下标不存在，则添加一个元素
a[1000]=5

echo${#a[@]}
echo${a[@]}

unset a[1]

echo${#a[@]}
echo${a[@]}

#截取数组操作
echo "截取"
a=(1 2 3 4 5)

#数组名[@/*]:起始位置:长度
echo ${a[@]:1:3}
echo ${a[@]}

c=${a[@]:1:4}
echo ${#c[@]}
echo ${c[@]}


#替换
echo "替换"
a=(1 2 3 4 5)

echo ${a[@]/3/100}
#不会修改原数组的内容
echo ${a[@]}


a=($a[@]/3/100)
echo ${a[@]}

#根据分隔符分割数组
a="one,two,three,four"

OLD_IFS="$IFS"
IFS=","
arr=($a)
IFS="$OLD_IFS"

for s in ${arr[@]}
do
    echo "$s"
done


# arr=($a)用于将字符串$a分割到数组$arr ${arr[0]} ${arr[1]} ... 分别存储分割后的数组第1 2 ... 项 ，${arr[@]}存储整个数组。变量$IFS存储着分隔符，这里我们将其设为逗号 "," OLD_IFS用于备份默认的分隔符，使用完后将之恢复默认。
