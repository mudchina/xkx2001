//Cracked by Roath
//ROOM: tulu_guangan_n.c

inherit ROOM;
string TULU_DESC_LONG=@LONG
这是京城西门外的土路，连接着广安门和西便门。土路西边
是一片荒地和小山丘，虽说离京城不远，但看起来也挺让人担心
是否有强人出没。东面是京城的城墙，厚实而高大。
LONG;


mapping TULU_EXITS=([
                "south" : __DIR__"guanganmen",
                "north" : __DIR__"tulu_xibian_s",
        ]);

#include "tulu.h"