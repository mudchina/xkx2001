//Cracked by Roath
// /d/shenlong/npcloc/zhangloc.c

// inherit SKILL;

inherit F_CLEAN_UP;

string *zhanglocs = ({
        "/d/changbai/jishi",
        "/d/city/yamen",
        "/d/dali/dinganfu",
        "/d/emei/baoguo1",
        "/d/forest/bank8",
        "/d/foshan/cunkou",
        "/d/hangzhou/kedian",
        "/d/huashan/siguoya",
        "/d/jiaxing/tieqiang",
        "/d/qilian/gulang",
        "/d/quanzhou/qzkedian",
        "/d/shaolin/ruzhou",
        "/d/shenlong/qianlong",
        "/d/taishan/shengxian",
        "/d/wudang/pine_road",
        "/d/xingxiu/yili",
        "/d/xixia/kedian",
        "/d/xueshan/shangu1",
});

void create() { seteuid(getuid()); }

string query_loc()
{
        return zhanglocs[random(sizeof(zhanglocs))];
}
