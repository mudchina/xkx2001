//Cracked by Roath
//ROOM: tulu_guangqu_n.c

inherit ROOM;

string TULU_DESC_LONG=@LONG
这是京城东面的土路，连接着东便门和广渠门。土路两
侧绿树成荫，夏天知了的叫声一阵阵的传来，让人心头痒痒
的。西面是京城的城墙，厚实而高大。
LONG;

mapping TULU_EXITS=([
                "south" : __DIR__"guangqumen",
                "north" : __DIR__"tulu_dongbian_s",
        ]);

#include "tulu.h"