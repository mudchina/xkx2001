//Cracked by Roath
#ifndef _NPC_SETUP_H_
#define _NPC_SETUP_H_

static string *menpai_list = ({
    "huashan", "shaolin", "wudang", "emei", "gaibang",
    "baituo", "xueshan", "xingxiu", "taohua" });

static mixed lastnamelist=({
({"赵", "zhao"}), ({"钱", "qian"}),  ({"孙", "sun"}),   ({"李", "li"}),
({"周", "zhou"}), ({"吴", "wu"}),    ({"郑", "zheng"}), ({"王", "wang"}),
({"冯", "feng"}), ({"陈", "chen"}),  ({"卫", "wei"}),   ({"高", "gao"}),
({"云", "yun"}),  ({"张", "zhang"}), ({"刘", "liu"}),   ({"马", "ma"}),
({"岳", "yue"}),  ({"程", "cheng"}), ({"何", "he"}),   ({"林", "lin"}),
({"潘", "pan"}),  ({"白", "bai"}), ({"向", "xiang"}),   ({"严", "yan"}),
({"方", "fang"}),  ({"余", "yu"}), ({"陆", "lu"}),   ({"贺", "he"}),
({"孟", "meng"}),  ({"谢", "xie"}), ({"徐", "xu"}),   ({"杨", "yang"}),
({"韩", "han"}),  ({"彭", "peng"}), ({"仇", "qiu"}),   ({"杨", "yang"}),
({"游", "you"}),  ({"任", "ren"}), ({"熊", "xiong"}),   ({"司马", "sima"}),
({"桑", "sang"}),  ({"泉", "quan"}), ({"金", "jin"}),   ({"丁", "ding"}),
({"田", "tian"}),  ({"上官", "shangguan"}), ({"莫", "mo"}),   ({"秦", "qin"}),
});

static mixed firstnamelist=({
({"金鳌", "jinao"}),   ({"吼", "hou"}), ({"克", "ke"}),
({"国梁", "guoliang"}), ({"光杰", "guangjie"}), ({"领军", "lingjun"}),
({"玄", "xuan"}),    ({"望海", "wanghai"}),  ({"千灵", "qianling"}),
({"青", "qing"}),    ({"伯山", "boshan"}),  ({"广义", "guangyi"}),
({"大雄", "daxiong"}),    ({"鹤", "he"}),  ({"九佳", "jiujia"}),
({"天恒", "tianheng"}),    ({"文亮", "wenliang"}),  ({"金鹏", "jinpeng"}),
({"涛", "tao"}),    ({"则成", "zecheng"}),  ({"石坚", "shijian"}),
({"评", "ping"}),    ({"建男", "jiannan"}),  ({"正鸿", "zhenghong"}),
({"天彪", "tianbiao"}),    ({"一邙", "yimang"}),  ({"泰", "tai"}),
({"智远", "zhiyuan"}),    ({"松年", "songnian"}),  ({"迅", "xun"}),
({"三星", "sanxing"}),    ({"孤桐", "gutong"}),  ({"柏英", "boying"}),
({"百童", "baitong"}),    ({"莲亭", "lianting"}),  ({"勉", "mian"}),
({"伯光", "boguang"}),    ({"云", "yun"}),  ({"南扬", "nanyang"}),
});

void set_random_name();

// sets full status (qi, jing, neili, jingli) according to level
void set_hp(int level);

// random menpai if parameter "menpai" given is 0
// return the menpai this npc has been assigned to
// sets "default_weapon" attribute
string set_skills(string menpai, int exp, int skill_rate);
#endif
