#include "json.c"

struct PKGVersion {
    char* version;
    char* url;
};

struct PKGHomebrew {
    char*        name;
    char*        title_id;
    char*        description;
    char*        icon;
    char*        latest;
    int          numScreenshots;
    char**       screenshots;
    int          numVersions;
    PKGVersion** versions;
};

int get_number_of_homebrews( json_t *json );
char *get_latest_url( PKGHomebrew &hb );
void get_homebrews( json_t *json, PKGHomebrew *homebrews );