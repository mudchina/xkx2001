//Cracked by Roath
//ROOM: tulu_zuoan_w.c

inherit ROOM;

string TULU_DESC_LONG=@LONG
这是京城南面的土路，连接着左安门和永安门。土路两
侧绿树成荫，夏天知了的叫声一阵阵的传来，让人心头痒痒
的。北面是京城的城墙，厚实而高大。
LONG;

mapping TULU_EXITS=([
                "east" : __DIR__"zuoanmen",
                "west" : __DIR__"tulu_yongan_e",
        ]);

#include "tulu.h"