//Cracked by Roath
// room: houyuan.c
// Jay 4/8/96
#include <room.h>

inherit ROOM;
int look_tai(string);

void create()
{
        set("short", "老宅后院");
        set("long", @LONG
这里是向阳老宅的后院。满地是发出朽烂霉气的落叶。院子的中央有一口
井，井台(tai)上刻着些字。院子南面有一扇门，但已被坍塌的砖瓦挡住了。
LONG
        );

        set("exits", ([
                "down" : __DIR__"well",
        ]));

        set("item_desc", ([
                "men" : "这扇门已被挡住无法通行，除非你打破(break)它。\n",
                "tai" : (:look_tai:),
        ]) );
	set("cost", 1);
        setup();
}

void init()
{
        add_action("do_break", "break");
        add_action("look_tai", "look");
}

int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="men" ) {
                write("不要随便打碎别人的东西！\n");
                return 1;
        }


        message_vision(
        "$N走到后门前，拜出骑马蹲裆式，深吸一口气，双掌同时拍出。\n", this_player());
        
        if (n>=200) {
        message_vision(
        "$N只听一声轰响，$N把门震开了！\n", this_player());
        set("exits/north", __DIR__"laozhai");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
        }

        return 1;
}

void close(object room)
{
        message("vision","门上的砖头瓦块稀里花拉坍塌下来，又挡住了小门。\n", room);
        room->delete("exits/north");
}

int look_tai(string arg)
{
        if( !arg || arg!="tai" ) return 0;
        write("井台上胡乱刻着许多脏话，其中一条是：\n");
        switch (random(15)) {
        case 0:
          write("林家没一个好东西，我×林远图林震南林平之的祖宗！\n");
          break;
        case 1:
          write("有了密码我就按，ＰＲＥＳＳ，按死这些龟儿子！\n");
          break;
        case 2:
          write("林平之这个小白脸生得有趣，大爷我真想把他当兔爷儿养起来。\n");
          break;
        case 3:
          write(this_player()->name()+"长得太丑了，大爷我看着一点儿性欲也没有。\n");
          break;
        case 4:
          write("你们这些人在别人家的井台上乱涂脏话，太不像话了！\n");
          break;
        case 5:
          write("嘿，孙子，老爷我骂的就是你！\n");
          break;
        case 6:
          write("ＧＯ　ＡＨＥＡＤ，　ＡＮＤ　ＭＡＫＥ　ＭＹ　ＤＡＹ！\n");
          break;
        case 7:
          write("我虽生为男身，可我好想当女人呦！\n");
          break;
        case 8:
          write("ｆｕｃｋ　ｙｏｕ，　ｍａｎ！\n");
          break;
        case 9:
          write("井里黑乎乎的，又没火照明，正好让我跟"+this_player()->name()+"快活快活！\n");
          break;
        case 10:
          write("说我下流，流到你家炕上了？！\n");
          break;
        case 11:
          write(this_player()->name()+"和翠花两个人瞎搞！\n");
          break;
        case 12:
          write("侬迭只老屁眼！\n");
          break;
        case 13:
          write("ｗｏ　ｃａｏ　ｎｉ　ｍａ　ｇｅ　ｂｉ ！\n");
          break;
        case 14:
          write("我丢你老某！\n");
          break;
        }
        return 1;
}

