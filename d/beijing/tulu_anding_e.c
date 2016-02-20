//Cracked by Roath
//ROOM: tulu_anding_e.c

inherit ROOM;

string TULU_DESC_LONG=@LONG
这是京城北面的土路，连接着东直门和安定门。土路两
侧绿树成荫，夏天知了的叫声一阵阵的传来，让人心头痒痒
的。南面是京城的城墙，厚实而高大。
LONG;

mapping TULU_EXITS=([
                "west" : __DIR__"andingmen",
                "east" : __DIR__"tulu_dongzhi_n",
        ]);

#include "tulu.h"