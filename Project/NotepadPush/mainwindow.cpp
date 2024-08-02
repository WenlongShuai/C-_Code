#include "mainwindow.h"
#include "ui_mainwindow.h"

int newfile_flag = 0;
int openfile_flag = 0;
QString last_savefile;  //最后一次保存文件的名字
QString last_fileContent;
QString text; //
int BlodCheck = 1;
bool ItalicCheck = true;
bool UderlineCheck = true;
QString filopenename;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //默认状态栏
    textedit->setFrameShape(QFrame::NoFrame);   //取消编辑框的边框
    ui->statusBar->addPermanentWidget(label4);
    ui->statusBar->addPermanentWidget(label3);
    ui->statusBar->addPermanentWidget(label2);
    ui->statusBar->addPermanentWidget(label1);
    ui->statusBar->addPermanentWidget(label5);

    //工具栏
    ui->mainToolBar->show(); //显示工具栏
    ui->mainToolBar->setAllowedAreas(Qt::LeftToolBarArea);
    ui->mainToolBar->setMovable(false);
    ui->mainToolBar->setFixedHeight(35);

    button10->setStyleSheet("border-image: url(:/1.jpg)");
    button11->setStyleSheet("border-image: url(:/2.jpg)");
    button12->setStyleSheet("border-image: url(:/3.jpg)");
    button13->setStyleSheet("border-image: url(:/4.png)");
    button14->setStyleSheet("border-image: url(:/5.png)");
    button15->setStyleSheet("border-image: url(:/6.png)");
    button16->setStyleSheet("border-image: url(:/7.png)");
    button17->setStyleSheet("border-image: url(:/9.jpg)");
    button18->setStyleSheet("border-image: url(:/10.jpg)");

    button10->setFlat(true);
    button11->setFlat(true);
    button12->setFlat(true);
    button13->setFlat(true);
    button14->setFlat(true);
    button15->setFlat(true);
    button16->setFlat(true);
    button17->setFlat(true);
    button18->setFlat(true);

    button10->setFixedSize(30,25);
    button11->setFixedSize(30,25);
    button12->setFixedSize(30,25);
    button13->setFixedSize(30,25);
    button14->setFixedSize(30,25);
    button15->setFixedSize(30,25);
    button16->setFixedSize(30,25);
    button17->setFixedSize(30,25);
    button18->setFixedSize(30,25);

    ui->mainToolBar->addWidget(button10);
    ui->mainToolBar->addWidget(button11);
    ui->mainToolBar->addWidget(button12);
    ui->mainToolBar->addWidget(button13);
    ui->mainToolBar->addWidget(button14);
    ui->mainToolBar->addWidget(button15);
    ui->mainToolBar->addWidget(button16);
    ui->mainToolBar->addWidget(button17);
    ui->mainToolBar->addWidget(button18);


    connect(button10,SIGNAL(clicked()),this,SLOT(bold_font()));
    connect(button11,SIGNAL(clicked()),this,SLOT(italic_font()));
    connect(button12,SIGNAL(clicked()),this,SLOT(underline()));
    connect(button13,SIGNAL(clicked()),this,SLOT(left_just()));
    connect(button14,SIGNAL(clicked()),this,SLOT(right_just()));
    connect(button15,SIGNAL(clicked()),this,SLOT(center_just()));
    connect(button16,SIGNAL(clicked()),this,SLOT(illustrate()));
    connect(button17,SIGNAL(clicked()),this,SLOT(ZoomInImage()));
    connect(button18,SIGNAL(clicked()),this,SLOT(ZoomOutImage()));

    //工作区
    this->setCentralWidget(textedit);  //设置默认字体

    //初始化字体
    textedit->setFont(QFont("微软雅黑",14));  //设置初始化字体

    //菜单栏
    menu[0] = ui->menuBar->addMenu("文件(&F)");
    action[0] = menu[0]->addAction("新建(N)");
    connect(action[0],SIGNAL(triggered()),this,SLOT(new_notepad()));
    action[0]->setShortcut(tr("Ctrl+N"));

    action[2] = menu[0]->addAction("打开(O)");
    connect(action[2],SIGNAL(triggered()),this,SLOT(open_notepad()));
    action[2]->setShortcut(tr("Ctrl+O"));

    action[3] = menu[0]->addAction("保存(S)");
    connect(action[3],SIGNAL(triggered()),this,SLOT(save_notepad()));
    action[3]->setShortcut(tr("Ctrl+S"));


    action[4] = menu[0]->addAction("另存为(A)");
    connect(action[4],SIGNAL(triggered()),this,SLOT(recast_notepad()));
    action[4]->setShortcut(tr("Ctrl+Shift+S"));

    action[28] = menu[0]->addAction("文件信息(I)");
    connect(action[28],SIGNAL(triggered()),this,SLOT(file_information()));
    action[28]->setShortcut(tr("Ctrl+I"));

    action[5] = menu[0]->addAction("页面设置(U)");
    connect(action[5],SIGNAL(triggered()),this,SLOT(page_setup_notepad()));
    action[5]->setShortcut(tr("Ctrl+U"));

    action[6] = menu[0]->addAction("打印(P)");
    connect(action[6],SIGNAL(triggered()),this,SLOT(print_notepad()));
    action[6]->setShortcut(tr("Ctrl+P"));

    menu[1] = ui->menuBar->addMenu("编辑(&E)");
    action[8] = menu[1]->addAction("撤销(U)");
    connect(action[8],SIGNAL(triggered()),this,SLOT(revocation_notepad()));
    action[8]->setShortcut(tr("Ctrl+Z"));

    action[1] = menu[1]->addAction("重做(R)");
    connect(action[1],SIGNAL(triggered()),this,SLOT(refrom_notepad()));
    action[1]->setShortcut(tr("Ctrl+Y"));

    action[9] = menu[1]->addAction("剪切(T)");
    connect(action[9],SIGNAL(triggered()),this,SLOT(cut_notepad()));
    action[9]->setShortcut(tr("Ctrl+X"));

    action[10] = menu[1]->addAction("复制(C)");
    connect(action[10],SIGNAL(triggered()),this,SLOT(copy_notepad()));
    action[10]->setShortcut(tr("Ctrl+C"));

    action[11] = menu[1]->addAction("粘贴(P)");
    connect(action[11],SIGNAL(triggered()),this,SLOT(paset_notepad()));
    action[11]->setShortcut(tr("Ctrl+V"));


    action[12] = menu[1]->addAction("删除(L)");
    connect(action[12],SIGNAL(triggered()),this,SLOT(delete_notepad()));
    action[12]->setShortcut(tr("Ctrl+Delete"));

    action[14] = menu[1]->addAction("查找(F)");
    connect(action[14],SIGNAL(triggered()),this,SLOT(lookup_notepad()));
    action[14]->setShortcut(tr("Ctrl+F"));

    action[17] = menu[1]->addAction("替换(R)");
    connect(action[17],SIGNAL(triggered()),this,SLOT(replace_motepad()));
    action[17]->setShortcut(tr("Ctrl+H"));

    action[18] = menu[1]->addAction("转到(G)");
    connect(action[18],SIGNAL(triggered()),this,SLOT(goto_notepad()));
    action[18]->setShortcut(tr("Ctrl+G"));

    action[19] = menu[1]->addAction("全选(A)");
    connect(action[19],SIGNAL(triggered()),this,SLOT(check_all_notepad()));
    action[19]->setShortcut(tr("Ctrl+A"));

    action[20] = menu[1]->addAction("时间/日期(D)");
    connect(action[20],SIGNAL(triggered()),this,SLOT(time_notepad()));
    action[20]->setShortcut(tr("Ctrl+5"));

    menu[2] = ui->menuBar->addMenu("格式(&O)");
    action[21] = menu[2]->addAction("自动换行(W)");
    connect(action[21],SIGNAL(triggered()),this,SLOT(line_warp_notepad()));
    action[21]->setShortcut(tr("Ctrl+W"));
    action[21]->setCheckable(true);
    action[21]->setChecked(true);

    action[22] = menu[2]->addAction("字体(F)");
    connect(action[22],SIGNAL(triggered()),this,SLOT(font_notepad()));
    action[22]->setShortcut(tr("Ctrl+1"));

    action[23] = menu[2]->addAction("颜色(C)");
    connect(action[23],SIGNAL(triggered()),this,SLOT(color_notepad()));
    action[23]->setShortcut(tr("Ctrl+2"));

    menu[3] = ui->menuBar->addMenu("查看(&V)");
    menu[4] = menu[3]->addMenu("缩放(Z)");
    action[24] = menu[4]->addAction("放大(I)");
    connect(action[24],SIGNAL(triggered()),this,SLOT(magnify_notepad()));
    action[24]->setShortcut(tr("Ctrl++"));

    action[25] = menu[4]->addAction("缩小(O)");
    connect(action[25],SIGNAL(triggered()),this,SLOT(shrink_notepad()));
    action[25]->setShortcut(tr("Ctrl+-"));

    action[26] = menu[4]->addAction("恢复默认缩放");
    connect(action[26],SIGNAL(triggered()),this,SLOT(defalut_notepad()));
    action[26]->setShortcut(tr("Ctrl+0"));

    action[7] = menu[3]->addAction("状态栏(S)");
    connect(action[7],SIGNAL(triggered()),this,SLOT(status_bar_notepad()));
    action[7]->setCheckable(true);
    action[7]->setChecked(true);
    connect(textedit, SIGNAL(cursorPositionChanged()), this,SLOT(status_notepad()));
    action[7]->setShortcut(tr("Ctrl+T"));

    menu[5] = ui->menuBar->addMenu("帮助(&H)");
    action[27] = menu[5]->addAction("关于记事本");
    connect(action[27],SIGNAL(triggered()),this,SLOT(about_notepad()));
    action[27]->setShortcut(tr("Ctrl+D"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about_notepad()
{
    QMessageBox::about(this,"关于记事本","有问题请联系：邮箱：2961070026@qq.com");
}

void MainWindow::new_notepad() //新建文件
{
    QMessageBox::StandardButton button = QMessageBox::information(this,"新建文件","是否新建文件",QMessageBox::Ok|QMessageBox::No);
    if(button == QMessageBox::Ok)
    {
        bool flag = false;
        textedit->clear();
        textedit->setHidden(flag);
        newfile_flag = 1;
        openfile_flag = 1;
    }
    else if(button == QMessageBox::No)
    {
        return;
    }
}

void MainWindow::open_notepad() //打开
{
    filopenename = QFileDialog::getOpenFileName(this,"打开文件","D:/","文本文件(*.txt);;word文件(*.doc *.docx);;所有文件(*.*)");
    if(filopenename.isEmpty()) //如果没有打开文件则直接退出
    {
        return;
    }
    else  //返回打开文件的路径
    {
        QTextCodec::ConverterState state;
        QFile file(filopenename);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray text;

        while(!file.atEnd()) //如果读完返回true，否则返回false
        {
            text = file.readAll();
            textedit->setPlainText(QTextCodec::codecForName("UTF-8")->toUnicode(text.constData()));

            if(state.invalidChars > 0)
            {
                QMessageBox::information(this,"信息提示","格式不匹配",QMessageBox::Ok);
            }
        }

        last_fileContent = QByteArray(text); //将QByteArray类型转换为QString类型

        QMessageBox::StandardButton putton = QMessageBox::information(this,"打开文件","打开文件成功",QMessageBox::Ok);
        if(putton == QMessageBox::Ok)
        {
            textedit->show();
            file.close();
            openfile_flag = 1;
        }
    }
}
void MainWindow::save_notepad() //保存
{
    QString filesavename;
    bool flag;
    bool flag2;
    QMessageBox::StandardButton button = QMessageBox::information(this,"保存文件","是否保存文件",QMessageBox::Ok|QMessageBox::No);
    if(button == QMessageBox::No)
    {
        return;
    }
    else if(button == QMessageBox::Ok)
    {
        if(newfile_flag)  //如果是新建的文件，则弹出对话框
        {
            filesavename = QFileDialog::getSaveFileName(this,"保存文件","D:/","文本文件(*.txt);;word文件(*.doc *.docx);;所有文件(*.*)");
            last_savefile = filesavename;
            if(filesavename.isEmpty())
            {
                return;
            }

            QFile file(filesavename); //把保存的文件路径写入
            flag = file.open(QIODevice::ReadWrite | QIODevice::Text);
            if(!flag)
            {
                QMessageBox::warning(this,"错误提示","打开文件失败",QMessageBox::Ok);
            }
            else
            {
                QTextStream str(&filesavename);
                QString str2 = textedit->toPlainText();
                file.write(str2.toUtf8());
            }

            QMessageBox::information(this,"保存文件","保存文件成功",QMessageBox::Ok);
            newfile_flag = 0;
            file.close();

        }
        else  //如果不是新建的则直接覆盖源文件
        {
            if(openfile_flag) //判断是否是存在文件
            {
                QFile file(last_savefile);
                flag2 = file.open(QIODevice::ReadWrite | QIODevice::Text);
                if(!flag2)
                {
                    QMessageBox::warning(this,"错误提示","打开文件失败",QMessageBox::Ok);
                }
                else
                {
                    QTextStream str3(&file);
                    QString str2 = textedit->toPlainText();
                    file.write(str2.toUtf8());
                    file.close();
                }
            }
        }
    }
}
void MainWindow::recast_notepad() //另存为
{
    QString file_another_savename = QFileDialog::getSaveFileName(this,"另存为文件","D:/","文本文件(*.txt);;word文件(*.doc *.docx);;所有文件(*.*)");
    if(file_another_savename.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(file_another_savename);
        bool flag = file.open(QIODevice::ReadWrite | QIODevice::Text);
        if(!flag)
        {
            QMessageBox::warning(this,"打开文件","打开文件失败",QMessageBox::Ok);
            return ;
        }
        QString text2 = textedit->toPlainText();
        file.write(text2.toUtf8());
        QMessageBox::information(this,"另存为文件","文件另存为成功",QMessageBox::Ok);
        file.close();
    }
}

void MainWindow::file_information() //文件信息
{
    QFileInfo file(filopenename);
    QString filename = file.fileName();  //获取文件名
    QString filepath = file.absolutePath(); //获取文件的绝对路径，不包括文件名
    qint64 filesize = file.size();  //获取文件大小
    QString s1 = "文件名：";
    QString s2 = "文件路径：";
    QString s3 = "文件大小：";
    QString fileinfomation1 = s1+filename;
    QString fileinfomation2 = s2+filepath;
    QString fileinfomation3 = s3+QString("%1").arg(filesize);

    textedit->insertPlainText(fileinfomation1 + "\n");
    textedit->insertPlainText(fileinfomation2 + "\n");
    textedit->insertPlainText(fileinfomation3 + "\n");

}
void MainWindow::page_setup_notepad()//页面设置
{
    qDebug()<<"页面设置"<<endl;
}

void MainWindow::print_notepad() //打印
{
    QPrintDialog printDialog(printer,parent);
    if(printDialog.exec() == QPrinter::DuplexAuto)
    {
        qDebug()<<"打印对话框"<<endl;
    }
}

void MainWindow::closeEvent(QCloseEvent *event) //关闭窗口
{
    if(textedit->toPlainText() == last_fileContent)
    {
        event->accept();
    }
    else
    {
        QMessageBox::StandardButton putton = QMessageBox::warning(this,"退出提示","您还未保存,确定退出吗？",QMessageBox::Yes | QMessageBox::No);
        if(putton == QMessageBox::Yes)
        {
            event->accept();
        }
        else if(putton == QMessageBox::No)
        {
            event->ignore();
        }
    }
}

void MainWindow::revocation_notepad() //撤销
{
    textedit->undo();

}
void MainWindow::refrom_notepad()  //重做
{
   textedit->redo();
}
void MainWindow::cut_notepad()  //剪切
{
    text = textedit->textCursor().selectedText();
    if(text.isEmpty())
    {
        text = textedit->toPlainText();
        QClipboard *clipboard = QGuiApplication::clipboard();
        clipboard->setText(text);
        textedit->cut();
        return;
    }
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(text);
    textedit->cut();
}
void MainWindow::copy_notepad()  //复制
{
    text = textedit->textCursor().selectedText();
    if(text.isEmpty())  //如果没有选中内容则全部复制
    {
        text = textedit->toPlainText();
    }
}
void MainWindow::paset_notepad()   //粘贴
{
    textedit->insertPlainText(text); //在光标当前位置插入内容
}
void MainWindow::delete_notepad()  //删除
{
    text = textedit->textCursor().selectedText();
    if(text.isEmpty())  //判断是否选择了要删的对象，是--true  否--false
    {
        textedit->textCursor().deletePreviousChar();  //删除光标前的字符
        return;
    }
    textedit->textCursor().deletePreviousChar(); //如果没有选择删除的字符串，则全部删除
}

void MainWindow::lookup_notepad()  //查找
{
    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("查找"));
    findDlg->setFixedSize(600,250);

    label6 = new QLabel("查找内容(N):",findDlg);
    label6->setFixedSize(80,40);
    label6->move(20,20);

    findLine = new QLineEdit(findDlg);
    findLine->setFixedSize(250,40);
    findLine->move(110,20);

    button1 = new QPushButton("查找下一个(F)",findDlg);
    button1->setFixedSize(110,40);
    button1->move(370,20);

    button2 = new QPushButton("取消",findDlg);
    button2->setFixedSize(110,40);
    button2->move(370,70);

    groupbox = new QGroupBox("方向",findDlg);
    groupbox->setFixedSize(170,70);
    groupbox->move(140,80);
    groupbox->setAlignment(Qt::AlignLeft);

    rad1 = new QRadioButton("向上(U)",findDlg);
    rad1->setFixedSize(80,40);
    rad1->move(145,100);

    rad2 = new QRadioButton("向下(D)",findDlg);
    rad2->setFixedSize(80,40);
    rad2->move(230,100);

    checkbox1 = new QCheckBox("区分大小写(C)",findDlg);
    checkbox1->setFixedSize(150,40);
    checkbox1->move(20,130);

    checkbox2 = new QCheckBox("循环(R)",findDlg);
    checkbox2->setFixedSize(150,40);
    checkbox2->move(20,150);

    connect(button1, SIGNAL(clicked()), this, SLOT(showFindText()));  //查找下一次按钮
    connect(button2,SIGNAL(clicked()),this,SLOT(cancalFindText()));   //取消按钮

//    connect(rad1,SIGNAL(),this,SLOT());  //向上查找
//    connect(rad2,SIGNAL(),this,SLOT());  //向下查找

    connect(checkbox1,SIGNAL(stateChanged(int)),this,SLOT(match_caseFindText(int)));   //区分大小写
    connect(checkbox2,SIGNAL(stateChanged(int)),this,SLOT(loopFindText(int)));   //循环

    QTextCursor tmp =textedit->textCursor();
    tmp.setPosition(0,QTextCursor::MoveAnchor);
    textedit->setTextCursor(tmp);

    findDlg->exec();
}

void MainWindow::showFindText()  //查找下一处
{
    QString str = findLine->text();
    if(flag == 0) //不区分大小写查找
    {
        bool ok;
        ok = textedit->find(str);
        if (ok)
        {
            QPalette palette = textedit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            textedit->setPalette(palette);
        }
        else if(!ok)
        {
            QMessageBox::warning(this, tr("查找"),
                    tr("找不到%1").arg(str));
            if(flag2 == 2)
            {
                QTextCursor tmp =textedit->textCursor();
                tmp.setPosition(0,QTextCursor::MoveAnchor);
                textedit->setTextCursor(tmp);
            }
        }
    }
    else if(flag == 2) //区分大小写查找
    {
        bool ok;
        ok = textedit->find(str,QTextDocument::FindCaseSensitively);
        if (ok)
        {
            QPalette palette = textedit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            textedit->setPalette(palette);

        }
        else if(!ok)
        {
            QMessageBox::warning(this, tr("查找"),
                    tr("找不到%1").arg(str));
            if(flag2 == 2)
            {
                QTextCursor tmp =textedit->textCursor();
                tmp.setPosition(0,QTextCursor::MoveAnchor);
                textedit->setTextCursor(tmp);
            }
        }
    }
}

void MainWindow::cancalFindText()  //取消查找
{
    findDlg->close();
}

void MainWindow::match_caseFindText(int a) //区分大小写
{
    flag = a;
}

void MainWindow::loopFindText(int b) //在查找中循环查找
{
    flag2 = b;
}

void MainWindow::replace_motepad()  //替换
{
    findDlg1 = new QDialog(this);
    findDlg1->setWindowTitle(tr("替换"));
    findDlg1->setFixedSize(600,250);

    label7 = new QLabel("查找内容(N):",findDlg1);
    label7->setFixedSize(85,40);
    label7->move(20,20);

    findLine1 = new QLineEdit(findDlg1);
    findLine1->setFixedSize(250,40);
    findLine1->move(110,20);

    button3 = new QPushButton("查找下一个(F)",findDlg1);
    button3->setFixedSize(110,40);
    button3->move(370,20);

    label8 = new QLabel("替换为(P):",findDlg1);
    label8->setFixedSize(85,40);
    label8->move(20,70);

    findLine2 = new QLineEdit(findDlg1);
    findLine2->setFixedSize(250,40);
    findLine2->move(110,70);

    button4 = new QPushButton("替换(R)",findDlg1);
    button4->setFixedSize(110,40);
    button4->move(370,70);

    button5 = new QPushButton("全部替换(A)",findDlg1);
    button5->setFixedSize(110,40);
    button5->move(370,120);

    button6 = new QPushButton("取消",findDlg1);
    button6->setFixedSize(110,40);
    button6->move(370,170);

    checkbox3 = new QCheckBox("区分大小写(C)",findDlg1);
    checkbox3->setFixedSize(150,40);
    checkbox3->move(20,170);

    checkbox4 = new QCheckBox("循环(R)",findDlg1);
    checkbox4->setFixedSize(150,40);
    checkbox4->move(20,190);

    connect(button3, SIGNAL(clicked()), this, SLOT(showFindText1()));  //查找下一次按钮
    connect(button4,SIGNAL(clicked()),this,SLOT(replaceText()));   //替换按钮
    connect(button5, SIGNAL(clicked()), this, SLOT(allReplaceText()));  //全部替换按钮
    connect(button6,SIGNAL(clicked()),this,SLOT(cancalFindText1()));   //取消按钮
    connect(checkbox3,SIGNAL(stateChanged(int)),this,SLOT(match_caseFindText1(int)));   //区分大小写
    connect(checkbox4,SIGNAL(stateChanged(int)),this,SLOT(loopFindText1(int)));   //循环

    QTextCursor tmp =textedit->textCursor();
    tmp.setPosition(0,QTextCursor::MoveAnchor);
    textedit->setTextCursor(tmp);

    findDlg1->exec();
}

void MainWindow::showFindText1()  //替换中的查找按钮的槽函数
{
    QString str = findLine1->text();

    if(flag1 == 0 ) //不区分大小写查找
    {
        bool ok;
        ok = textedit->find(str);
        if (ok)
        {
            QPalette palette = textedit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            textedit->setPalette(palette);
        }

        else if(!ok)
        {
            if(flag3 == 0)
            {
                QMessageBox::warning(this, tr("查找"),
                        tr("找不到%1").arg(str));
            }
            else if(flag3 == 2)
            {
                //将光标移动在开始位置
                QTextCursor tmp =textedit->textCursor();
                tmp.setPosition(0,QTextCursor::MoveAnchor);
                textedit->setTextCursor(tmp);
            }
        }
    }
    else if(flag1 == 2) //区分大小写查找
    {
        bool ok;
        ok = textedit->find(str,QTextDocument::FindCaseSensitively);
        if (ok)
        {
            QPalette palette = textedit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            textedit->setPalette(palette);

        }
        else if(!ok)
        {
            if(flag3 == 0)
            {
                QMessageBox::warning(this, tr("查找"),
                        tr("找不到%1").arg(str));
            }
            else if(flag3 == 2)
            {
                //将光标移动在开始位置
                QTextCursor tmp =textedit->textCursor();
                tmp.setPosition(0,QTextCursor::MoveAnchor);
                textedit->setTextCursor(tmp);
            }
        }
    }

}

void MainWindow::replaceText() //替换中的替换按钮的槽函数
{
    static int x = 0;
    QString str = findLine1->text(); //获取需要查找的内容
    QString str2 = textedit->toPlainText(); //读取文本内容
    QString str1 = findLine2->text(); //需要替换的内容

    if(flag1 == 0)
    {
        bool ok;
        ok = textedit->find(str);
        if(ok)
        {
            QPalette palette = textedit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            textedit->setPalette(palette);

            x = textedit->textCursor().position();
            str2.replace(x-1,1,str1);  //替换
            textedit->setPlainText(str2);  //将替换好字符串写进去
        }
        else if(!ok)
        {
            if(flag3 == 0)
            {
                QMessageBox::warning(this, tr("查找"),
                        tr("找不到%1").arg(str));
            }
            else if(flag3 == 2)
            {
                //将光标移动在开始位置
                QTextCursor tmp =textedit->textCursor();
                tmp.setPosition(0,QTextCursor::MoveAnchor);
                textedit->setTextCursor(tmp);
            }

        }
    }
    else if(flag1 == 2)
    {
        bool ok;
        ok = textedit->find(str,QTextDocument::FindCaseSensitively);
        if(ok)
        {
            QPalette palette = textedit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            textedit->setPalette(palette);

            x = textedit->textCursor().position();
            str2.replace(x-1,1,str1);  //替换
            textedit->setPlainText(str2);  //将替换好字符串写进去
        }
        else if(!ok)
        {
            if(flag3 == 0)
            {
                QMessageBox::warning(this, tr("查找"),
                        tr("找不到%1").arg(str));
            }
            else if(flag3 == 2)
            {
                //将光标移动在开始位置
                QTextCursor tmp =textedit->textCursor();
                tmp.setPosition(0,QTextCursor::MoveAnchor);
                textedit->setTextCursor(tmp);
            }
        }
    }

}

void MainWindow::allReplaceText()  //全部替换
{
    QString str = findLine1->text(); //获取需要查找的内容
    QString str1 = findLine2->text(); //需要替换的内容
    QString str2 = textedit->toPlainText(); //读取文本内容

    if(flag1 == 0)
    {
        if(!textedit->find(str))
        {
            QPalette palette = textedit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            textedit->setPalette(palette);


            str2.replace(str,str1,Qt::CaseInsensitive);  //替换
            textedit->setPlainText(str2);//将替换好字符串写进去
        }

    }

    else if(flag1 == 2)
    {
        if(!textedit->find(str,QTextDocument::FindCaseSensitively))
        {
            QPalette palette = textedit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            textedit->setPalette(palette);

            str2.replace(str,str1,Qt::CaseSensitive);  //替换
            textedit->setPlainText(str2);  //将替换好字符串写进去
        }
    }
}

void MainWindow::cancalFindText1() //替换中的取消
{
    findDlg1->close();
}

void MainWindow::match_caseFindText1(int a) //替换中区分大小写
{
    flag1 = a;
}

void MainWindow::loopFindText1(int b)  //在替换中的循环
{
    flag3 = b;
}


void MainWindow::goto_notepad()  //转到
{
    findDlg2 = new QDialog(this);
    findDlg2->setWindowTitle("转到指定行");
    findDlg2->setFixedSize(370,170);

    label9 = new QLabel("行号(L)：",findDlg2);
    label9->setFixedSize(80,40);
    label9->move(20,10);

    findLine3 = new QLineEdit(findDlg2);
    findLine3->setFixedSize(250,40);
    findLine3->move(20,50);

    button7 = new QPushButton("转到",findDlg2);
    button7->setFixedSize(80,40);
    button7->move(100,110);


    button8 = new QPushButton("取消",findDlg2);
    button8->setFixedSize(80,40);
    button8->move(190,110);

    connect(button7,SIGNAL(clicked()),this,SLOT(gotoLineText()));

    connect(button8,SIGNAL(clicked()),this,SLOT(cancelGoto()));

    findDlg2->exec();
}

void MainWindow::gotoLineText() //转到槽函数
{
    bool ok;
    QString a = findLine3->text();
    int count = 0;
    int num = a.toInt(&ok); //将Qstring转换成int，ok用来存储是否成功转换，如果成功转换则为true
    if(ok)
    {
        QTextBlock block = textedit->document()->findBlockByNumber(num);
        textedit->setTextCursor(QTextCursor(block));

        count = textedit->document()->lineCount();
        if(num > count)
        {
            QMessageBox::warning(this,"跳行","跳转的行数超过总行数",QMessageBox::Ok);
        }
        if(num <= count)
        {
            findDlg2->close();
        }
    }
}

void MainWindow::cancelGoto()  //取消转到
{
    findDlg2->close();
}

void MainWindow::check_all_notepad()  //全选
{
    textedit->selectAll();  //选择文本所有内容
    //高亮所选内容
    QPalette palette = textedit->palette();
    palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
    textedit->setPalette(palette);
}
void MainWindow::time_notepad()  //时间
{
    QDateTime *time = new QDateTime;
    QString str = time->currentDateTime().toString("yyyy年MM月dd日 hh:mm:ss");
    textedit->insertPlainText(str);
}

void MainWindow::line_warp_notepad()   //自动换行
{
    bool ok = action[21]->isChecked();
    if(ok == true)
    {
        textedit->setWordWrapMode(QTextOption::WrapAnywhere);
    }
    if(ok == false)
    {
        textedit->setWordWrapMode(QTextOption::NoWrap);
    }
}
void MainWindow::font_notepad()   //字体
{
    bool flag;
    //getFont(&flag,plain->font() //从编辑框里获取字体
    QFont font = QFontDialog::getFont(&flag,textedit->font(),this,"字体选择提示框");
    if(flag)
    {
        textedit->setFont(font);  //将设置好的字体设置到编辑框
    }
}
void MainWindow::color_notepad() //颜色
{
    QPalette palette = textedit->palette();  //获取编辑框的调色板
    QColor color = palette.color(QPalette::Text);  //在获取编辑框里字体颜色
    QColor color2 = QColorDialog::getColor(color,this,"颜色选择提示框"); //将编辑框里的字体颜色设置为调色板的初始颜色
    if(color2.isValid())
    {
        palette.setColor(QPalette::Text,color2); //在调色板上设置字体的颜色
        textedit->setPalette(palette); //设置好颜色后，再把它设置到编辑框
    }
}

void MainWindow::magnify_notepad()  //放大
{
    if(count < 500)
    {
        textedit->zoomIn(2);  //放大文本
        count += 10;
        MainWindow::status_notepad();
    }
}

void MainWindow::shrink_notepad()  //缩小
{
    if(count > 10)
    {
        textedit->zoomOut(2);  //缩小文本
        count -=10;
        MainWindow::status_notepad();
    }
}
void MainWindow::defalut_notepad()  //默认大小
{
    textedit->setFont(QFont("微软雅黑",14));
}

void MainWindow::status_bar_notepad() //状态栏
{
    bool ok = action[7]->isChecked();
    if(ok == true)
    {
    }ui->statusBar->show();
    if(ok == false)
    {
        ui->statusBar->close();
    }
}

void MainWindow::status_notepad()   //状态栏
{
    linenum = textedit->textCursor().blockNumber();  //光标所在行数
    column = textedit->textCursor().columnNumber();  //获取所在列数

    QString Line = QString("%1").arg(linenum);
    QString Column = QString("%1").arg(column);
    QString s1 = "第";
    QString s2 = "行";
    QString s3 = "第";
    QString s4 = "列";
    QString s5 = ",";
    QString splice = s1+Line+s2+s5+s3+Column+s4;
    label4->setText(splice);

    QString s6 = QString("%1").arg(count);
    QString s7 = "%";
    QString splice2 = s6+s7;
    label3->setText(splice2);

    ui->statusBar->addPermanentWidget(label4);
    ui->statusBar->addPermanentWidget(label3);
    ui->statusBar->addPermanentWidget(label2);
    ui->statusBar->addPermanentWidget(label1);
    ui->statusBar->addPermanentWidget(label5);
}

void MainWindow::wheelEvent(QWheelEvent * Event)  //滚轮控制字体大小
{
    if ((Event->modifiers() == Qt::ControlModifier))
    {
        if(Event->delta() > 0)
        {
            if(count < 500)
            {
                textedit->zoomIn(2);
                count+=10;
                MainWindow::status_notepad();
            }
        }
        else if(Event->delta() < 0)
        {

            if(count > 10)
            {
                textedit->zoomOut(2);
                count -= 10;
                MainWindow::status_notepad();
            }
        }
    }
    Event->accept();
}

void MainWindow::bold_font()  //加粗
{
    QTextCharFormat bdf;
    bdf.setFontWeight(BlodCheck?QFont::Bold : QFont::Normal);
    mergrFormat(bdf);
    BlodCheck = !BlodCheck;
}

void MainWindow::italic_font()  //斜体
{
    QTextCharFormat icf;
    icf.setFontItalic(ItalicCheck?true : false);
    mergrFormat(icf);
    ItalicCheck = !ItalicCheck;
}

void MainWindow::underline()   //下划线
{
    QTextCharFormat udl;
    udl.setFontUnderline(UderlineCheck?true : false);
    mergrFormat(udl);
    UderlineCheck = !UderlineCheck;
}

void MainWindow::left_just()  //左对齐
{
    textedit->setAlignment(Qt::AlignLeft);
}

void MainWindow::right_just()  //右对齐
{
    textedit->setAlignment(Qt::AlignRight);
}

void MainWindow::center_just()  //居中对齐
{
    textedit->setAlignment(Qt::AlignHCenter);
}

void MainWindow::illustrate()  //插入图片
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                      ".", tr("Bitmap Files (*.bmp)\n"
                                        "JPEG (*.jpg *jpeg)\n"
                                        "GIF (*.gif)\n"
                                        "PNG (*.png)\n"));
        QUrl Uri ( QString ( "file://%1" ).arg ( file ) );
        QImage image = QImageReader ( file ).read();

        QTextDocument * textDocument = textedit->document();
        textDocument->addResource( QTextDocument::ImageResource, Uri, QVariant ( image ) );
        QTextCursor cursor = textedit->textCursor();
        QTextImageFormat imageFormat;
        imageFormat.setWidth( image.width() );
        imageFormat.setHeight( image.height() );
        imageFormat.setName( Uri.toString() );
        cursor.insertImage(imageFormat);
}

void MainWindow::ZoomInImage()
{
    //获取文本编辑游标
    QTextCursor cursor = textedit->textCursor();
    //判断游标是否有选中内容
    if(cursor.hasSelection())
    {
        //判断游标选中内容是否包含图片
        if(cursor.selection().toHtml().contains("img src="))
        {
           //获取选中内容的html语句
           QString img_html = cursor.selection().toHtml();
           //定义一个用于记录图片语句长度的变量
           int str_size = 0;
           //从语句开始，到该语句结束（结束条件是 />）
           for(int i = img_html.indexOf("<img src=") + 10; i < img_html.length(); ++i)
           {
                ++str_size;
                if(img_html.mid(i, 2) == "/>")
                {
                    //减2是因为不想多拿到height=“xxx” /> 此处的右引号与空格
                    str_size -= 2;
                    break;
                }
            }

            //截取出字符串
            QString str_temp = img_html.mid(img_html.indexOf("<img src=") + 9, str_size);

            //获取高度
            QString temp_height;
            for(int i = str_temp.indexOf("height=") + 8; i < str_temp.length(); ++i)
            {
                   temp_height += str_temp[i];
            }

            QString temp_width;  //获取宽度
            for(int i = str_temp.indexOf("width=") + 7; i < str_temp.length()-14; ++i)
            {
                   temp_width += str_temp[i];
            }

            //修改高度，放大1.5倍
            int temp_height_int = temp_height.toInt() * 1.5;
            //修改宽度，放大1.5倍
            int temp_width_int = temp_width.toInt() * 1.5;
            //替换高度
            str_temp.replace(temp_height, QString("%1").arg(temp_height_int));
            //替换宽度
            str_temp.replace(temp_width, QString("%1").arg(temp_width_int));
            //替换图片html语句
            img_html.replace(img_html.mid(img_html.indexOf("<img src=") + 9, str_size), str_temp);
            //清除选中的语句，重新插入语句
            cursor.deleteChar();
            textedit->insertHtml(img_html);
        }
    }
}

void MainWindow::ZoomOutImage()
{
    QTextCursor cursor = textedit->textCursor();
    if(cursor.hasSelection())
    {
        if(cursor.selection().toHtml().contains("img src="))
        {
            QString img_html = cursor.selection().toHtml();
            int str_size = 0;
            for(int i = img_html.indexOf("<img src=") + 10; i < img_html.length(); ++i)
            {
                ++str_size;
                if(img_html.mid(i, 2) == "/>")
                {
                str_size -= 2;
                break;
                }
            }

            //截取字符串
            QString str_temp = img_html.mid(img_html.indexOf("<img src=") + 9, str_size);
            //获取高度
            QString temp_height;
            for(int i = str_temp.indexOf("height=") + 8; i < str_temp.length(); ++i)
            {
               temp_height += str_temp[i];
            }
            //获取宽度
            QString temp_width;
            for(int i = str_temp.indexOf("width=") + 7; i < str_temp.length()-14; ++i)
            {
               temp_width += str_temp[i];
            }


            int temp_height_int = temp_height.toInt() / 1.5;
            int temp_width_int = temp_width.toInt() / 1.5;

            str_temp.replace(temp_height, QString("%1").arg(temp_height_int));
            str_temp.replace(temp_width, QString("%1").arg(temp_width_int));

            img_html.replace(img_html.mid(img_html.indexOf("<img src=") + 9, str_size), str_temp);

            cursor.deleteChar();
            textedit->insertHtml(img_html);
        }
    }
}


void MainWindow::mergrFormat(QTextCharFormat fmt)
{
    QTextCursor cursor = textedit->textCursor();
    if (!cursor.hasSelection())
    {
      cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(fmt);
}

