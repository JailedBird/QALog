# QAdb

基于Qt实现跨平台Adb日志工具



## 问题记录

1、 Qt Designer QSplitter不跟随窗口生效

答：ui模块设计完毕之后，使用代码直接将QSplitter对象设置为中心区域、而非基于设计器的实现（用Widget保住Splitter，导致无法缩放）

2、使用文本输入框承载日志内容，输出错误&多打印换行

答： 使用append API对自动加上换行，应该使用insert API，但是他的文本输出内容和光标位置挂钩，每次设置时应该重置光标到行尾；

如下：xml中设置只读不写；通过代码插入内容

```
<property name="readOnly">
   <bool>true</bool>
</property>
ui->plainTextEdit->moveCursor(QTextCursor::End);
ui->plainTextEdit->insertPlainText(str);
```



### 