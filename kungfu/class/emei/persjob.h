//Cracked by Roath
// /kungfu/class/emei/pers_job.h
// yasuko: 2000/09/13
#include <ansi.h>

string* place = ({
        "/d/city/kedian",
        "/d/dali/dlkd1",
        "/d/hangzhou/kedian",
        "/d/qilian/kedian",
        "/d/quanzhou/qzkedian",
        "/d/shaolin/kedian1",
        "/d/xixia/kedian",
//        "/d/xiangyang/kedian",
//        "/d/beijing/kedian",
});

string* area = ({
        "扬州",
        "大理",
        "杭州",
        "永登",
        "泉州",
        "南阳",
        "西夏",
//        "襄阳",
//        "北京",
});

string ask_for_job()
{
        object ob,obj,me=this_player();
        int i;
        string meet_room,room;
        if (me->query("family/family_name")!="峨嵋派") {
                command ("smile ");
                return RANK_D->query_respect(this_player())+"也会劝驾吗？";
        }
        if (me->query_condition("get_pers_job") &&!me->query("last_finished")) {
                command ("hmm ");
                return "上回交给你的任务还没办完吧......";
        }
        if (me->query_condition("get_pers_job") &&me->query("last_finished")) {
                command ("hehehe ");
                return "托郭祖师的福，最近好象挺太平的。";
        }
        command ("nod ");
        i=random(sizeof(place));
        meet_room=place[i];
        if (me->query("id")=="yasuko") tell_object(me,sprintf("i:%d, area:%s, place:%s \n",i,area[i],meet_room));
        if (obj=!find_object(meet_room)) obj=load_object(meet_room);
        room=->obj->query("short");
        ob=new("/d/emei/npc/guide");
        ob->move(obj);
        return "好吧，那就相烦"+RANK_D->query_respect(this_player())+"速去"+area[i]+"的"+room+"，那儿有同门等着你接应呢。";
}
