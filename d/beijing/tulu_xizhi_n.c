//Cracked by Roath
//ROOM: tulu_xizhi_n.c

inherit ROOM;

string TULU_DESC_LONG=@LONG
这是京城西门外的土路，连接着得胜门和西直门。由于离城
门比较近，这里的治安比较好。四处可以看到乘凉的百姓。东面
是京城的城墙，厚实而高大。
LONG;

mapping TULU_EXITS=([
                "south" : __DIR__"xizhimen",
                "north" : __DIR__"tulu_desheng_sw",
        ]);

#include "tulu.h"