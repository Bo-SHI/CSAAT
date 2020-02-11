# 搭建阿里云主机(主机环境创建)

### 主机环境
> centos 7.4

---
### linux 用户相关
> useradd (新建用户并设置密码)
> useradd -s /bin/sh -d /home/username -m username
> passwd username

---
> visudo -- 新建用户增加sudo权限(root)

### git 相关
> sudo yum install git -- 安装
> git config --global user.name "username"
> git config --global user.email "email@email.com"

---
> ssh-keygen -t rsa -C "email@email.com" -- 生成ssh key
> /home/username/.ssh/id_rsa.pub -- 公钥
