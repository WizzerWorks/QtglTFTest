To build the QtHelp files, use the following commands:


Generate the QtHelp Compressed File
===================================

On Windows, do

<qt_installation_dir>\bin\qhelpgenerator glTF.qhp -o glTF.qch

where <qt_installation_dir is something like C:\Users\msm\bin\Qt5.0.2\5.0.2\msvc2010_opengl

or, on Linux, do

qhelpgenerator glTF.qhp -o glTF.qch


Generate the QtHelp File Collection
===================================

On Windows, do

<qt_installation_dir>\bin\qcollectiongenerator QtglTFTest.qhcp -o QtglTFTest.qhc

where <qt_installation_dir is something like C:\Users\msm\bin\Qt5.0.2\5.0.2\msvc2010_opengl

or, on Linux, do

qhelpgenerator QtglTFTest.qhcp -o QtglTFTest.qhc

Copy Generated Files
===================+

Copy glTF.qch and QtglTFTest.qhc to "C:\\Users\\msm\tmp" on Windows or "/home/msm/tmp" on Linux. This location may be changed, but you will first need to modify helpdialog.h and change the hard-coded path.

This is just a temporary solution until an installation process is developed.
