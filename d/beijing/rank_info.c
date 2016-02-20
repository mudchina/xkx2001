//Cracked by Roath
// rank_info.h

string *rank_name = ({
    "城门千总",
    "城门守备",
    "骁骑营佐领",
    "侍卫营参领",
    "侍卫营一等侍卫",
    "副都统",
    "都统",
});

string *juewei_name = ({
    "云骑尉",
    "骑都尉",
    "三等轻车都尉", "二等轻车都尉", "一等轻车都尉",
    "三等男爵", "二等男爵", "一等男爵",
    "三等子爵", "二等子爵", "一等子爵",
    "三等伯爵", "二等伯爵", "一等伯爵",
    "三等侯爵", "二等侯爵", "一等侯爵",
    "三等公爵", "二等公爵", "一等公爵",
});

int *suicong_max = ({
    0, 0, 0, 1, 2, 3, 4,
});

int *rank_position_num = ({36, 24, 16, 12, 8, 4, 2});
int *rank_upgrade_num = ({36, 24, 16, 12, 8, 4, 2});

// 5 years
// int tuiyi_pending_time = 1296000;
// for debugging, only 1 min
int tuiyi_pending_time = 60;
