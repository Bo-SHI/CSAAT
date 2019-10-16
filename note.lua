print [[
    2019/10/10

    Linux 用户和用户组管理:
      useradd 选项 用户名   --新增用户
        选项: -c 添加用户描述
              -s 指定Shell
              -d 指定目录
              -m 如果目录不存在,创建目录,通常与-d一起使用
              -g 指定用户组
              -G 指定附加组
              -u 指定用户号
        example: useradd -s /bin/sh -d /home/user -m user -g group -G root,... user

      userdel 选项 用户名   --删除用户
        选项: -r 删除主目录
        example: userdel -r user

      usermod 选项 用户名   --修改用户
        选项: 与useradd 一致
        example: usermod -s /bin/bash -d /home/z user

      passwd 选项 用户名    --用户口令管理
        选项: -l 锁定口令,即禁止用户
              -u 口令解锁
              -d 使账号无口令
              -f 强迫用户下次登录修改口令
        example: passwd user

      groupadd 选项 用户组  --新增用户组
        选项: -g 指定用户组的组表示号(GID)
              -o 一般与-g同时使用,表示新的用户组GID可以与系统已有用户组的GID相同
        example: groupadd -g 1000 group

      groupdel 用户组   --删除用户组
        example:groupdel group

      groupmod 选项 用户组  --修改用户组的属性
        选项: 同groupadd
              -n 新用户组,更改用户组名字
        example: groupmod -g 10000 -n group3 group2

      newgrp 用户组     --用户如果有多个组,可以切换
        example: newgrp root

    与用户组相关文件:
        /etc/passwd /etc/group /etc/shadow


    SSH
        ssh-keygen -t rsa -C "email@email.com"
        ~/.ssh/id_rsa.pub   --公钥
]]

print [[
    2019/10/11

    -- pthread 相关
    pthread_key_t
    pthread_key_create
    pthread_setspcific
    pthread_getspcific
]]

print [[
    shadowsocks for linux/centos
]]

print [[
    2019/10/15
    algorithm : binary_search
    gdb install

    LD_LIBRARY_PATH
    gcc source.c -shared -fPIC -o object.so
    gcc source.c -L. -llib_name -o a.out
]]
