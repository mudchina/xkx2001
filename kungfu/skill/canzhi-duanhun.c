//Cracked by Roath
// bloody.c 残肢断魂,for 那个PK我的王八！！
//chaos 31/3/97 午夜零点狂怒变身后作。

inherit SKILL;

mapping *action = ({
([      "action" : "$N一手扳住$n上腭，一手扳住下颌，用力一分，把$n下巴撕了下来",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "抓伤"
]),
([      "action" : "$N扑向$n，一口咬住$n的喉咙，喀嚓一声$n的食管，气管，血管全都被撕得希巴烂，像一堆烂麻绳",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "抓伤"
]),
([      "action" : "$N五指插进$n天灵盖，喀的一声扳开头骨，把$n脑浆一把抓了出来，舔了几口",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "抓伤"
]),
([      "action" : "$N一手摁住$n喉咙，咬向$n胸腹，三两口就啃得见了肋骨，几下就把$n胸腹肌肉撕扯殆尽，心肺等内脏清晰可见",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "抓伤"
]),
([      "action" : "$N一声狞笑，踩住$n脊背，抓住$n双手，啪的一声将两臂硬拽了下来，手臂与身体连接处血肉模糊，白骨森森",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "抓伤"
]),
([      "action" : "$N踩住$n的背，一用劲，咯的一声闷响，$n的脊椎骨断成十七二十八截，$N再从$n身体中血淋淋地扯出半条不成模样的脊椎骨",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "抓伤"
]),
([      "action" : "$N抓住$n两条腿，使劲一撕，把$n撕成两片，鲜血四溅，$n的内脏稀里乎噜流了一地",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "抓伤"
]),
([      "action" : "$N两指嵌入$n眼睛，使劲抓牢，一手抓住$n身体，用劲一绞，一扭，再一扯，一下就把$n的头拽了下来",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "抓伤"
]),

});

int valid_enable(string usage) { return usage == "claw" || usage == "parry"; }

int valid_learn(object me)
{
	
		return notify_fail("你不能学残肢断魂。\n");
	
}


mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	
		return notify_fail("你不能练残肢断魂。\n");
	
} 



