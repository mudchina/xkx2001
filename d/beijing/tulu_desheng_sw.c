//Cracked by Roath
//ROOM: tulu_desheng_sw.c

inherit ROOM;

string TULU_DESC_LONG=@LONG
这是京城西北的土路，连接着得胜门和西直门。土路两
侧绿树成荫，夏天知了的叫声一阵阵的传来，让人心头痒痒
的。东南面是京城的城墙，厚实而高大。
LONG;

mapping TULU_EXITS=([
                "south" : __DIR__"tulu_xizhi_n",
                "northeast" : __DIR__"deshengmen",
        ]);

#include "tulu.h"