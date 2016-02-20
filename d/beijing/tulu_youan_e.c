//Cracked by Roath
//ROOM: tulu_youan_e.c

inherit ROOM;

string TULU_DESC_LONG=@LONG
这是京城南门外的土路，连接着永安门和右安门。土路南边
是一些农田，一阵微风吹来，你竟然可以闻到卖穗的清香。北面
是京城的城墙，厚实而高大。
LONG;

mapping TULU_EXITS=([
                "east" : __DIR__"tulu_yongan_w",
                "west" : __DIR__"youanmen",
        ]);

#include "tulu.h"