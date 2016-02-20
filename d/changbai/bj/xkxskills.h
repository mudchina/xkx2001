//Cracked by Roath
// /d/changbai/bj/bjskills.h
// by  ALN  2/98


mapping *info_weapon = ({
([      "type": "blade",
        "weapons" : ({
                "/clone/weapon/gangdao",
                "/clone/weapon/jiedao",
                "/clone/weapon/lingpai",
                "/d/changbai/obj/tiepai",
                "/clone/weapon/tongbo",
                "/clone/weapon/wandao",
                "/clone/weapon/miandao",
                }),
        "skills" : ({
                "cibei-dao"
                "liangyi-dao",
                "liuhe-dao",
                "luan-blade",
                "taiji-dao",
                "wuhu-duanmen",
                "xiuluo-dao",
                "xue-dao",
                "yanxing-dao",
                }),
]),

([      "type": "club",
        "weapons" : ({
                "/clone/weapon/jingun",
                "/clone/weapon/panguanbi",
                "/clone/weapon/qimeigun",
                "/clone/weapon/tiegun",
                "/d/changbai/obj/tongren",
                }),
        "skills"   : ({
                "weituo-gun",
                "wuhu-gun",
                "zui-gun",
                }),
]),

([      "type": "hammer",
        "weapons" : ({
                "/clone/weapon/faling",
                "/clone/weapon/falun",
                "/clone/weapon/hammer",
                "/clone/weapon/hothammer",
                "/clone/weapon/liuxing",
                "/clone/weapon/lubo",
                "/clone/weapon/mubei",
                "/clone/weapon/tieqiao",
                "/clone/weapon/tiesuanpan",
                "/clone/weapon/yaochu",
                }),
        "skills"   : ({
                "riyue-lun",
                }),
]),

([      "type": "hook",
        "weapons" : ({
                "/clone/weapon/hook",
                }),
        "skills"   : ({
                "ruyi-gou",
                }),
]),

([      "type": "pike",
        "weapons" : ({
                "/clone/weapon/gangzhua",
                "/clone/weapon/qiang",
                "/clone/weapon/sangucha",
                }),
        "skills"   : ({
                "liuhe-qiang",
                "san-sword",
                }),
]),

([      "type": "staff",
        "weapons" : ({
                "/clone/weapon/chanzhang",
                "/clone/weapon/fachu",
                "/clone/weapon/gangzhang",
                "/clone/weapon/shezhang",
                "/clone/weapon/tiejiang",
                "/clone/weapon/tiezhang",
                "/clone/weapon/yaoqin",
                }),
        "skills"   : ({
                "fengmo-zhang",
                "jingang-chu",
                "lingshe-zhang",
                "pudu-zhang",
                "tianshan-zhang",
                "wuchang-zhang",
                }),
]),

([      "type": "stick",
        "weapons" : ({
                "/clone/weapon/gangbang",
                "/clone/weapon/langya-bang",
                "/clone/weapon/tiebang",
                }),
        "skills"   : ({
                "dagou-bang",
                }),
]),


([      "type": "sword",
        "weapons" : ({
                "/clone/weapon/changjian",
                "/clone/weapon/emeici",
                "/clone/weapon/fachi",
                "/clone/weapon/gangjian",
                "/clone/weapon/qinggang-jian",
                "/clone/weapon/tiexiao",
                }),
        "skills"   : ({
                "damo-jian",
                "duanjia-jian",
                "dugu-jiujian",
                "fumo-jian",
                "huashan-jianfa",
                "huifeng-jian",
                "jinshe-jianfa",
                "mingwang-jian",
                "pixie-jian",
                "taiji-jian",
                "tangshi-jian",
                "wugou-jianfa",
                "yuxiao-jian",
                }),
]),

([      "type": "whip",
        "weapons" : ({
                "/clone/weapon/changbian",
         //       "/clone/weapon/dulong-bian",
                "/clone/weapon/fuchen",
        //        "/clone/weapon/heilong-bian",
                }),
        "skills"   : ({
                "feifeng-bian",
                "riyue-bian",
                }),
]),
});              

mapping unarmed_skills = ([
        "claw"  : ({
                "jiuyin-zhao",
                "juehu-zhua",
                "longzhua-gong",
                "sanyin-zhua",
                "yingzhua-gong",
                }),

        "cuff"  : ({
                "jingang-quan",
                "jinyu-quan",
                "luohan-quan",
                "pishi-poyu",
                "taiji-quan",
                "wuxing-quan",
                "yanqing-quan",
                "yujiamu-quan",
                }),

        "finger": ({
                "nianhua-zhi",
                "tanzhi-shentong",
                "tiangang-zhi",
                "yiyang-zhi",
                "yizhi-chan",
                }),

        "hand"  : ({
                "dashou-yin",
                "fengyun-shou",
                "lanhua-fuxue",
                "qianye-shou",
                "shexing-diaoshou",
                "zhemei-shou",
                }),                

        "kick"  : ({
                "jueming-tui",
                "xuanfeng-saoye",
                }),

        "strike": ({
                "chousui-zhang",
                "cuixin-zhang",
                "huagu-mianzhang",
                "hunyuan-zhang",
                "huoyan-dao",
                "jinding-zhang",
                "luoying-shenjian",
                "qingyan-zhang",
                "sanhua-zhang",
                "wuyu-zhangfa",
                "xianglong-zhang",
                "youshen-zhang",
                }),                
]);

string *dodge_skills = ({
        "ding-dodge",
        "duanshi-shenfa",
        "huashan-shenfa",
        "lingshe-shenfa",
        "liuxing-bu",
        "luoying-shenfa",
        "poem-dodge",
        "shaolin-shenfa",
        "shenkongxing",
        "tiyunzong",
        "wuxingbu",
        "xiaoyaoyou",
        "xueshitiao",
        "zhaixinggong",
        "zhutian-bu",
});

string *force_skills = ({
        "ding-force",
        "dulong-dafa",
        "hamagong",
        "huagong-dafa",
        "huntian-qigong",
        "hunyuan-yiqi",
        "kurong-changong",
        "linji-zhuang",
        "longxiang-banruo",
        "taiji-shengong",
        "taixuan-gong",
        "xiaowuxiang",
        "zixia-gong",
});
