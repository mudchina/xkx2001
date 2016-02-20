//Cracked by Roath
// Summer 9/12/96, qfy 5/99

#include <ansi.h>
#include "room.h"

inherit ROOM;

string* regions = ({
        "/d/changbai/",
        "/d/city/",
        "/d/dali/",
        "/d/emei/",
        "/d/forest/",
        "/d/foshan/",
        "/d/gaibang/",
        "/d/huanghe/",
        "/d/huashan/",
        "/d/jiaxing/",
        "/d/qilian/",
        "/d/quanzhou/",
        "/d/shaolin/",
        "/d/taihu/",
        "/d/taohua/",
        "/d/village/",
        "/d/wudang/",
        "/d/xingxiu/",
        "/d/xixia/",
        "/d/xueshan/",
        "/d/zhongnan/",
});

void create()
{
        set("short", "地牢");
        set("long", @LONG
一个空荡荡的牢房，四周徒有厚实的墙壁。由于深在地底的缘故，空气混浊
得令人有点受不了。
LONG
        );

        set("no_fight", 1);

        set("cost", 0);
        setup();

        call_out("free_victim", 1800);
}

int valid_leave(object me, string dir)
{
        if( me->query_temp("rysj_prisoner") ) {
                me->delete_temp("rysj_prisoner");
        }

        return ::valid_leave(me, dir);
}

int free_victim()
{
        string region, *rooms, room, place;
        object dest, *objs, *prisoners, luckyguy;
        int i, num;

        region = regions[random(sizeof(regions))];
        rooms = get_dir(region);

        if ( sizeof(rooms) == 0 ) {
                remove_call_out("free_victim");
                call_out("free_victim", 1);

                return 1;
        }

        room = rooms[random(sizeof(rooms))];

        if ( sscanf(room, "%s.c", room) ) {
                place = region+room;

                if ( !dest = find_object(place) )
                        dest = load_object(place);

                if ( objectp(dest) ) {
                        objs = all_inventory(this_object());
                        prisoners = allocate(sizeof(objs));

                        for ( i=0; i<sizeof(objs); i++ ) {
                            if ( objs[i]->is_character() && userp(objs[i]) ) {
                                prisoners[num] = objs[i];
                                num++;
                            }
                        }

                        if ( num > 0 ) {
                                luckyguy = prisoners[random(num)];

                                message_vision("地牢的门忽然开了，两个日月神教卫士走了进来。\n", luckyguy);
                                message_vision("日月神教卫士大略张望了一阵，便朝$N走了过来。\n", luckyguy);
                                message_vision("一个日月神教卫士对$N嘿嘿奸笑道：大爷奉命让你上路！\n", luckyguy);
                                message_vision("接着日月神教卫士突然一指点在$N的昏睡穴上。\n", luckyguy);

                                if( !wizardp(luckyguy) ) luckyguy->unconcious();

                                message_vision("日月神教卫士将$N像死狗般的拖了出地牢去，门也被锁上了。\n", luckyguy);
                                luckyguy->move(dest);
                        }
                }
                else {
                        remove_call_out("free_victim");
                        call_out("free_victim", 1);

                        return 1;
                }
        
                remove_call_out("free_victim");
                call_out("free_victim", 1800);
        }
        else {
                remove_call_out("free_victim");
                call_out("free_victim", 1);
        }

        return 1;
}
