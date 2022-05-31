# 毕设文档仓库

本仓库是我的毕设文档仓库，内容包括：

1. 相关参考文献；
2. 相关参考代码；
3. HarmonyOS学习资料和笔记；
4. MPU6050参考资料和参考代码；
5. Max30102参考资料和参考代码
6. w800芯片官方文档；
7. pcb工程；
8. cortex-M3资料；
9. 支持向量机测试代码（python）；
10. 微信小程序工程；

毕业论文文件夹添加在gitignore文件中，并未上传。


**毕设题目：** 老年可穿戴传感器研究与开发老年人可穿戴传感器的研究与开发

**基本思路：** 系统分为3个部分——硬件设备、云、应用。设备采集老人心率和血氧饱和度数据、并实时判断老人是否跌倒；数据通过MQTT协议上传至华为云；家人使用微信小程序实时访问云端数据；老人跌倒时由华为云发送报警短信到指定手机。

**原材料：**

1. Neptune w800 开发板；
2. MPU6050；
3. Max30102；
4. 华为云IAM账号；
5. 手机；


设备侧代码在另一仓库，地址：[CQUPTLei / Neptune_w800_project](https://github.com/CQUPTLei/Neptune_w800_project)


时间：2022-05-31

作者：CQUPTLEI
