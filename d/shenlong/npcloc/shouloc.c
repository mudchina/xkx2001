//Cracked by Roath
// /d/shenlong/npcloc/shouloc.c

// inherit SKILL;

inherit F_CLEAN_UP;

string *shoulocs = ({
        "/d/city/duchang",
        "/d/changbai/xrguan", 
        "/d/dali/yaopu",
        "/d/forest/huanghebang1",
        "/d/foshan/yxlou",
        "/d/hangzhou/lingyin0",
        "/d/qilian/dangpu",
        "/d/quanzhou/laozhai",
        "/d/shaolin/shanmen",
        "/d/shenlong/tingkou",
        "/d/taishan/baihe",
        "/d/xingxiu/house",
        "/d/xixia/ypgate",
        "/d/xueshan/shanmen",
});

void create() { seteuid(getuid()); }

string query_loc()
{
        return shoulocs[random(sizeof(shoulocs))];
}
