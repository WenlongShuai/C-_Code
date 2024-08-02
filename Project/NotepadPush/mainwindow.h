#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
#include <QMenu>
#include <QWidget>
#include <QAction>
#include <QTextEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QStatusBar>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QToolBar>
#include <QTextCodec>
#include <QByteArray>
#include <QPrinter>
#include <QPrintDialog>
#include <QDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QTextCursor>
#include <QUndoCommand>  //在其他操作中如果要使用重做和撤销则需要使用这个类
#include <QClipboard>
#include <QTextBlock>
#include <QTextDocument>
#include <QDateTime>
#include <QShortcut>
#include <QKeySequence>
#include <QMoveEvent>
#include <QScrollArea>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QToolBar>
#include <QFileInfo>

#include <QImage>
#include <QImageReader>
#include <QAbstractScrollArea>
#include <QString>

#include <QTextDocumentFragment>

class QLineEdit;
class QDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTextEdit *textedit=new QTextEdit;

    QTextCursor mergeformat;

public slots:
    void about_notepad(); //执行关于记事本的槽函数
    void new_notepad(); //执行新建文件的槽函数
    void open_notepad();  //打开
    void save_notepad(); //保存
    void recast_notepad();  //另存为
    void file_information(); //文件信息
    void page_setup_notepad(); //页面设置
    void print_notepad(); //打印
    virtual void closeEvent(QCloseEvent *event); //关闭文件的事件处理

    void revocation_notepad(); //撤销
    void refrom_notepad();  //重做
    void cut_notepad();  //剪切
    void copy_notepad();  //复制
    void paset_notepad();   //粘贴
    void delete_notepad();  //删除
    void lookup_notepad();  //查找
    void replace_motepad();  //替换
    void goto_notepad();   //转到
    void check_all_notepad();  //全选
    void time_notepad();  //时间

    void line_warp_notepad();   //自动换行
    void font_notepad();   //字体
    void color_notepad();  //颜色

    void magnify_notepad();  //放大
    void shrink_notepad();   //缩小
    void defalut_notepad();  //默认大小
    void status_bar_notepad(); //状态栏
    void status_notepad(); //行列状态栏
  //  void status_notepad2(); //缩放字体显示状态栏

    //查找的槽函数
    void showFindText();  //查找中的查找下一个按钮
    void cancalFindText();  //取消查
    void match_caseFindText(int a);  //区分大小写
    void loopFindText(int b);   //循环

    //替换的槽函数
    void showFindText1();  //查找中的查找下一个按钮
    void replaceText();   //替换查找到的文本
    void allReplaceText();  //全部替换按钮
    void cancalFindText1();  //取消查找
    void match_caseFindText1(int a);  //区分大小写
    void loopFindText1(int b);   //循环

    //转到的槽函数
    void gotoLineText();  //转到对应的行
    void cancelGoto();   //取消转到

    virtual void wheelEvent(QWheelEvent *event);  //鼠标滚轮触发事件

    //工具栏的槽函数
    void bold_font();   //加粗
    void italic_font(); //斜体
    void underline();   //下划线
    void left_just();   //左对齐
    void right_just();  //右对齐
    void center_just(); //居中对齐
    void illustrate();  //插入图片
    void ZoomInImage();  //放大图片
    void ZoomOutImage(); //缩小图片

    void mergrFormat(QTextCharFormat fmt);  //设置字体格式的选区

private:
    Ui::MainWindow *ui;


    QAbstractScrollArea *center = new QAbstractScrollArea;
    QMenu **menu = new QMenu*[6]; //菜单项
    QAction **action = new QAction*[29];  //执行动作变量

    //工具栏
    QToolBar *toolbar = new QToolBar;//工具栏
    QPushButton *button10 = new QPushButton;
    QPushButton *button11 = new QPushButton;
    QPushButton *button12 = new QPushButton;
    QPushButton *button13 = new QPushButton;
    QPushButton *button14 = new QPushButton;
    QPushButton *button15 = new QPushButton;
    QPushButton *button16 = new QPushButton;
    QPushButton *button17 = new QPushButton;
    QPushButton *button18 = new QPushButton;

    //状态栏显示休息
    QLabel *label1 = new QLabel("UTF-8");
    QLabel *label2 = new QLabel("Windows(CRLF)");
    QLabel *label3 = new QLabel("100%");
    QLabel *label4 = new QLabel("第0行,第一列");
    QLabel *label5 = new QLabel("       ");

    //配置两个打印对话框的构造参数
    QPrinter *printer = new QPrinter;
    QWidget *parent = new QWidget;

    //查找界面
    QLineEdit *findLine;
    QDialog *findDlg;
    QLabel *label6;
    QPushButton *button1;
    QPushButton *button2;
    QCheckBox *checkbox1;
    QCheckBox *checkbox2;
    QGroupBox *groupbox;
    QRadioButton *rad1;
    QRadioButton *rad2;

    //替换界面
    QLineEdit *findLine1;
    QLineEdit *findLine2;
    QDialog *findDlg1;
    QLabel *label7;
    QLabel *label8;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QCheckBox *checkbox3;
    QCheckBox *checkbox4;

    //转到
    QLineEdit *findLine3;
    QDialog *findDlg2;
    QLabel *label9;
    QPushButton *button7;
    QPushButton *button8;

    int flag = 0;//该变量来存储查找是否区分大小写
    int flag1 = 0;//该变量来存储替换是否区分大小写
    int flag2 = 0; //该变量来存储查找是否循环查找
    int flag3 = 0; //该变量来存储替换是否循环查找
    int linenum = 0;  //光标所在行数
    int column = 0;  //获取所在列数
    int count = 100;
};

#endif // MAINWINDOW_H
