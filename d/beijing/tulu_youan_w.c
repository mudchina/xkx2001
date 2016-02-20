//Cracked by Roath
//ROOM: tulu_youan_w.c

inherit ROOM;

string TULU_DESC_LONG=@LONG
这是京城南门外的土路，连接着广安门和右安门。土路南边
是一些农田，一阵微风吹来，你竟然可以闻到卖穗的清香。东北
面是京城的城墙，厚实而高大。
LONG;

mapping TULU_EXITS=([
                "north" : __DIR__"tulu_guangan_s",
                "east" : __DIR__"youanmen",
        ]);

#include "tulu.h"