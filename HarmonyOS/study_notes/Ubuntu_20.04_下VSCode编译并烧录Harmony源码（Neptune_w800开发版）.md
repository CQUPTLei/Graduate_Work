昨天写过一篇文章，是在<font color=green>**命令行编译**</font>，使用命令行串口工具<font color=orange>**minicom**</font>烧录的。有点小麻烦。

推荐大家先试用上述方法试一试，里面要安装的依赖也在文章里面。[文章链接](https://blog.csdn.net/weixin_43764974/article/details/124052484?spm=1001.2014.3001.5501)

鸿蒙Dev Device Tool本身就是VSCode的一个扩展，在VSCode中试用图形界面一站式开发更加快捷。

<font color=green>**鸿蒙开发学习我建议直接上Ubuntu+VScode，不用切换系统搞来搞去的。**</font>

本文将介绍在Ubuntu+VScode环境下鸿蒙源码编译与烧录的全过程。（这里用的是在gitee拉取的工程，本文先不讲工程各个目录、文件的作用，先走一遍完整过程）

鸿蒙开发者社区：[https://device.harmonyos.com/cn/community/](https://device.harmonyos.com/cn/community/)，遇到问题除了百度、csdn搜索，还可以在这里搜索，很多开发者都会遇到类似的问题。

@[TOC](<center> 目录</center>)

# 1.获取源码
我的开发板是<font color=red>**Neptune w800**</font>，是HiHope公司（润和软件）的，直接去他们gitee的仓库拉取代码。

地址：

```bash
https://gitee.com/hihopeorg_group/neptune-harmony-os1.1-iot
```
下载后解压放到合适位置就先不用管了：

![在这里插入图片描述](https://img-blog.csdnimg.cn/3265e5aa57014933ab87f2e1acf65126.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
# 2.搭建开发环境
这里是在vscode中使用DevEco Device Tool ，工具链（gn、hc-gen、ninja）都会在下载DevEco Device Tool 的时候一并下载好，位置在：

> /home/jaychou/.deveco-device-tool

后面在工程配置的时候还会说到。


如果你在命令行编译就要参考我上一篇文章进行环境配置了。

除此之外：<font color=green>**VSCode和Python3.8是必需的**</font>，python3.8在ubunut20.04中本来就有，vscode下载安装就行了。

## 2.1 DevEco Device Tool 安装
### 2.1.1 将Ubuntu Shell环境修改为bash

1. 执行如下命令，确认输出结果为bash。如果输出结果不是bash，请根据步骤2，将Ubuntu shell修改为bash。

```bash
ls -l /bin/sh
```

```bash
jaychou@jaychou-TM1705:~$ ls -l /bin/sh
lrwxrwxrwx 1 root root 4 4月   8 15:56 /bin/sh -> bash
```

2. 打开终端工具，执行如下命令，输入密码，然后选择No，将Ubuntu shell由dash修改为bash。

```bash
sudo dpkg-reconfigure dash
```
### 2.1.2 下载DevEco Device Tool 3.0 Release Linux版本。
地址：[DevEco Device Tool 3.0 Release Linux](https://device.harmonyos.com/cn/develop/ide#download)
1. 解压：

```bash
unzip devicetool-linux-tool-3.0.0.400.zip
```
2. 赋予可操作权限：

```bash
chmod 777 devicetool-linux-tool-3.0.0.400.sh
```
3. 安装：

```bash
sudo ./devicetool-linux-tool-3.0.0.400.sh -- --install-plugins
```
安装成功，界面输出“Deveco Device Tool successfully installed.”。

4. 打开vscode查看：
![在这里插入图片描述](https://img-blog.csdnimg.cn/8a16320c604a4dc4a7ad7cde45f63925.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

## 2.2 导入工程
1. 打开DevEco Device Tool，进入Home页，点击**Import Project**打开工程
![在这里插入图片描述](https://img-blog.csdnimg.cn/0cf534b3d76a45c19ef345b974edcb6b.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16)
2. 选择待打开的工程目录，点击**Import**打开。
![在这里插入图片描述](https://img-blog.csdnimg.cn/38aa934a50f2456f8af979a91090267d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_16,color_FFFFFF,t_70,g_se,x_16#pic_center)
3. 打开的目录不是DevEco Device Tool工程，则会出现如下提示框，点击**Import**。
![在这里插入图片描述](https://img-blog.csdnimg.cn/df18ac49bde04a40a93e39bb5b84cb93.png)
4. 在Select Project type界面，选择**Import from OpenHarmony Source**。
![在这里插入图片描述](https://img-blog.csdnimg.cn/fed257c269954d389c11dbff3a06d346.png)
5. 在Import Project界面，选择Product后，会自动填充对应的MCU、Board、company和kernel信息，然后ohosVersion选择对应的OpenHarmony源码版本。(我的已经打开过了，不用选，这里放的是鸿蒙官网HI386的开发版，操作都是类似的)![在这里插入图片描述](https://img-blog.csdnimg.cn/5af5441952c64613b823a025cf17a0d8.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16)
6. 点击Open打开工程或源码。
![在这里插入图片描述](https://img-blog.csdnimg.cn/49e84d8a23364c3da94993f51deee5e2.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)




## 2.3 工程配置（重点）
如图，在VSCode左侧菜单栏点击**DevEco——Quick Access——主界面——工程设置**，出现下面的配置界面。

![在这里插入图片描述](https://img-blog.csdnimg.cn/b228c15f82c64026a4f0a65738519075.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

### 2.3.1工具链构建
工具链存放路径是默认设置好的，在那个目录下存放着如下工具：

![在这里插入图片描述](https://img-blog.csdnimg.cn/c8c3b56d4df74282a8e258a80b82b166.png#pic_center)
之前的文章有简介，此处不再重复。这一步一般不用你设置。

OpenHarmony版本选1.x，根据实际选择即可。

产品是wifiiot的，这些一般都不需要多余配置。

接下来是构建OpenHarmony的工具链，点击详情，可以看到鸿蒙需要的各种包如下，类型也不尽相同，有deb、pip等等，如果安装好了，就像下面一样status显示valid，否则是红色的<font color=red>**invalid**</font>。

![在这里插入图片描述](https://img-blog.csdnimg.cn/4fdacc45a09848c48adb1ccdbc6409ae.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
如果缺少包，点击下面的安装按钮，即可自动在线安装。可能会有部分包安装失败，需要自己手动安装。我当时是python的2个包，解决方法如下：

[Python安装 scons、pycryptodome等各种库很慢、安装失败](https://blog.csdn.net/weixin_43764974/article/details/124061186?spm=1001.2014.3001.5502)
### 2.3.2 编译器下载与配置
再往下，就是编译器的路径配置了。Neptune  w800使用的是<font color=green>**国产指令集c-sky**</font>(可自行百度)，不同于一般arm芯片的RISC精简指令集。所以需要下载对应的编译器。

编译器资源在平头哥的网站：[https://occ.t-head.cn/community/download](https://occ.t-head.cn/community/download)，进去选择 工具 - 工具链-800 Series 中相应的版本。

名称：csky-elfabiv2-tools-x86_64-minilibc-xxxxx.tar.gz

下载完成后将工具包拷贝到相应的目录下，我的是：~/HarmonyOS_Tool（我试用命令行编译方式的时候工具的存放目录）

解压：(注意你的压缩包名字)

```bash
tar xzvf csky-elfabiv2-tools-x86_64-minilibc-20210423.tar.gz
```

在~/.bashrc文件添加环境变量（根据你的路径来）：

```bash
sudo gedit ~/.bashrc
```

```bash
export PATH=~/HarmonyOS_Tool/csky-elfabiv2-tools-x86_64-minilibc-20210423/bin:$PATH
```

刷新环境变量：

```bash
source ~/.bashrc
```
回到vscode中选择相同的目录：
![在这里插入图片描述](https://img-blog.csdnimg.cn/b4281560f09b4f8ab142760e61348cd1.png#pic_center)
### 2.3.3 w800执行配置
上面都是toolchain下面的配置，接着对w800选项进行配置。需要设置的有：

<font color=orange>**build_type**:</font>默认为debug
<font color=orange>**upload_partitions**：</font>选择待烧录的文件名称。
<font color=orange>**upload_port**：</font>选择烧录的串口（下面马上讲）。
<font color=orange>**upload_protocol**：</font>选择烧录协议，固定选择“xmodem”。

![在这里插入图片描述](https://img-blog.csdnimg.cn/b9017af74caa43f4874a9057e2eac892.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_18,color_FFFFFF,t_70,g_se,x_16#pic_center)
怎么知道串口是哪个呢？如下（方法不唯一），可以看到在23：06分我的/dev/ttyUSB0上连接了开发版，上面的upload_port填写/dev/ttyUSB0即可。

```bash
jaychou@jaychou-TM1705:~$  ls -l /dev/ttyUSB*
crw-rw-rw- 1 root dialout 188, 0 4月   9 23:06 /dev/ttyUSB0
```

# 3.编译与下载

如图。
<font color=purple>**clean**：</font>清除之前编译的内容。
<font color=purple>**build**：</font>编译（只编译项目更改的内容，相对更快一点）。
<font color=purple>**rebuild**：</font>重新编译。
<font color=purple>**upload**：</font>烧录。
<font color=purple>**monitor**：</font>和串口助手这类工具类似，可以实时监视串口输出。

下面按步骤进行说明。
![在这里插入图片描述](https://img-blog.csdnimg.cn/314ebb9067ec4b0d8d880c7a3e4aa545.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_10,color_FFFFFF,t_70,g_se,x_16#pic_center)
## 3.1 Build
在各种环境配置好之后，点击Build，可能会出现以下报错：
![在这里插入图片描述](https://img-blog.csdnimg.cn/946a1d199581417c900d2533b214c220.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
找不到clang编译器，解决方法：

下载llvm安装包：

```bash
sudo wget https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar
```
解压，我是复制到前面说过的/HarmonyOS_ToolHarmonyOS_Tool文件夹下面才解压的：

```bash
sudo tar -xvf llvm-linux-9.0.0-36191.tar 
```
同样的，在环境变量中添加路径：

```bash
export PATH=~/HarmonyOS_Tool/llvm/bin:$PATH
```
再刷新环境变量就可以了。

再次编译：

![在这里插入图片描述](https://img-blog.csdnimg.cn/f6bf9ae94114448c908304f0ddc45d63.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

## 3.2 Upload
编译完成之后，插上开发版，点击Upload，可能会出现下面报错：
![在这里插入图片描述](https://img-blog.csdnimg.cn/2b1f013d123f4eeabf0cd5c65ff76fa5.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
即打不开对应的端口，为什么呢？

来到linux，最敏感的一个东西就是文件的权限了：读、写、执行。
来我给/dev/ttyUSB0权限不就OK了？直接最高权限（滑稽）

```bash
sudo chmod 777 /dev/ttyUSB0
```
再次烧录，确实OK了。但下一次烧写就有不行了，我不能每一次都赋予一遍权限吧。

我直接给USB to TTL设备权限：通过增加udev规则来实现，步骤如下：

```bash
sudo gedit /etc/udev/rules.d/70-ttyusb.rules
```

在文件内增加一行

```bash
KERNEL=="ttyUSB[0-9]*", MODE="0666"
```
重新插入，直接一劳永逸。

成功烧录：（按照提示按一下板子上的reset）
![在这里插入图片描述](https://img-blog.csdnimg.cn/141b2eb05e9b420485c5a8e1e104e08c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

## 3.3 Monitor

点击Monitor，重启设备，看到输出：
![在这里插入图片描述](https://img-blog.csdnimg.cn/ca9aecc220f148f1b6aa8a91e6a388a9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5oSf6LCi5Zyw5b-D5byV5Yqb,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

<hr>
<font color=purple size=8>遇到困难？欢迎评论！</font>
