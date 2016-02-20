//Cracked by Roath
//ROOM: tulu_fucheng_n.c

inherit ROOM;

string TULU_DESC_LONG=@LONG
这是京城西门外的土路，连接着阜成门和西便门。土路西边
是一片荒地和小山丘，虽说离京城不远，但看起来也挺让人担心
是否有强人出没。东面是京城的城墙，厚实而高大。
LONG;

mapping TULU_EXITS=([
        "north" : __DIR__"tulu_xizhi_s",
        "south" : __DIR__"fuchengmen",
]);

#include "tulu.h"