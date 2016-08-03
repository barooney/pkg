#define VITASDK

#include <psp2/sysmodule.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/display.h>

#include <jansson.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>

#include "graphics.h"
#include "json.h"

int get_number_of_homebrews( json_t *json ) {
    int size = json_array_size( json );
    return size;
}

char *get_latest_url( PKGHomebrew &hb ) {
    int versionCount = hb.numVersions;
    for ( int y = 0; y < versionCount; y++ ) {
        if ( 0 == strcmp( hb.versions[ y ]->version, hb.latest ) ) {
            return hb.versions[ y ]->url;
        }
    }
    return NULL;
}

void get_homebrews( json_t *json, PKGHomebrew *homebrews ) {
    size_t i;
    json_t *value;
    json_t *jsonHomebrew;
    json_array_foreach( json, i, jsonHomebrew ) {

        // general info
        homebrews[i].name        = ( char* ) json_string_value( json_object_get( jsonHomebrew, "name" ) );
        homebrews[i].title_id    = ( char* ) json_string_value( json_object_get( jsonHomebrew, "TITLEID" ) );
        homebrews[i].description = ( char* ) json_string_value( json_object_get( jsonHomebrew, "description" ) );
        homebrews[i].latest      = ( char* ) json_string_value( json_object_get( jsonHomebrew, "latest" ) );
        homebrews[i].icon        = ( char* ) json_string_value( json_object_get( jsonHomebrew, "icon" ) );

        // screenshots
        size_t screenshotCounter = 0;
        json_t* jsonScreenshots = json_object_get( jsonHomebrew, "screenshots" );
        json_t* jsonScreenshot;
        homebrews[ i ].numScreenshots = json_array_size( jsonScreenshots );
        homebrews[ i ].screenshots = new char *[ homebrews[ i ].numScreenshots ];
        json_array_foreach( jsonScreenshots, screenshotCounter, jsonScreenshot ) {
            homebrews[ i ].screenshots[ screenshotCounter ] = ( char* ) json_string_value( jsonScreenshot );
        }

        // versions
        size_t versionCounter = 0;
        json_t* jsonVersions = json_object_get( jsonHomebrew, "versions" );
        const char *versionNumber;
        json_t *versionUrl;
        homebrews[ i ].numVersions = json_object_size( jsonVersions );
        homebrews[ i ].versions = new PKGVersion *[ homebrews[ i ].numVersions ];
        json_object_foreach( jsonVersions, versionNumber, versionUrl ) {
            PKGVersion *v = new PKGVersion;
            v->version = ( char* ) versionNumber;
            v->url = ( char* ) json_string_value( versionUrl );
            homebrews[ i ].versions[ versionCounter ] = v;
            versionCounter++;
        }
    }
}

// Usage example
/*void read_homebrews {
    json_t *json;
    json_error_t error;

    size_t count;

    json = json_load_file( "ux0:temp/sample.json", 0, &error );
    if ( ! json ) {
        psvDebugScreenPrintf( "Error while loading:\n" );
        psvDebugScreenPrintf( "%s:\n", error.text );
    }

    if ( JSON_ARRAY != json_typeof( json ) ) {
        psvDebugScreenPrintf( "Error: JSON is not an Array.\n" );
    } else {
        int size = get_number_of_homebrews( json );
        struct PKGHomebrew homebrews[ size ];
        get_homebrews( json, homebrews );
    }
}*/