#define VITASDK

#include <psp2/sysmodule.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/display.h>

#include <jansson.h>

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "graphics.h"

struct PKGVersion {
	char* version;
	char* url;
	PKGVersion* next;
};

struct PKGHomebrew {
	char* name;
	char* title_id;
	char* description;
	char* icon;
	char** screenshots;
	PKGVersion** versions;
};

void read_homebrews( json_t *json ) {
	int size = json_array_size( json );
	psvDebugScreenPrintf("JSON array contains %d homebrews.\n\n", size );
	struct PKGHomebrew homebrews[size];

	size_t i;
	json_t *value;
	json_t *jsonHomebrew;
	json_array_foreach( json, i, jsonHomebrew ) {

		psvDebugScreenPrintf( "addr: 0x%08X with index %d\n", jsonHomebrew, i );
		
		// general info
		homebrews[i].name        = ( char* ) json_string_value( json_object_get( jsonHomebrew, "name" ) );
		homebrews[i].title_id    = ( char* ) json_string_value( json_object_get( jsonHomebrew, "TITLEID" ) );
		psvDebugScreenPrintf( "Found homebrew %s (%s)\n", homebrews[i].name, homebrews[i].title_id );

		homebrews[i].description = ( char* ) json_string_value( json_object_get( jsonHomebrew, "description" ) );
		psvDebugScreenPrintf( "Description: %s\n", homebrews[i].description );

		homebrews[i].icon        = ( char* ) json_string_value( json_object_get( jsonHomebrew, "icon" ) );
		psvDebugScreenPrintf( "Icon:        %s\n", homebrews[i].icon );

		// screenshots
		size_t screenshotCounter = 0;
		json_t* jsonScreenshots = json_object_get( jsonHomebrew, "screenshots" );
		json_t* jsonScreenshot;
		int screenShotLength = json_array_size( jsonScreenshots );
		psvDebugScreenPrintf( "number of screenshots: %d\n", screenShotLength );

		psvDebugScreenPrintf( "homebrews[%d].screenshots, length = %d\n", i, screenShotLength );
		homebrews[i].screenshots = new char *[screenShotLength];
		json_array_foreach( jsonScreenshots, screenshotCounter, jsonScreenshot ) {
			homebrews[i].screenshots[screenshotCounter] = ( char* ) json_string_value( jsonScreenshot );
			psvDebugScreenPrintf( "%s\n", homebrews[i].screenshots[screenshotCounter] );
		}

		// versions
		size_t versionCounter = 0;
		json_t* jsonVersions = json_object_get( jsonHomebrew, "versions" );
		int versionLength = json_object_size( jsonVersions );
		psvDebugScreenPrintf( "number of versions: %d\n", versionLength );

		homebrews[i].versions = new PKGVersion *[versionLength];
		
		const char *versionNumber;
		json_t *versionUrl;
		json_object_foreach( jsonVersions, versionNumber, versionUrl ) {
			homebrews[i].versions[versionCounter]->version = ( char* ) versionNumber;
			homebrews[i].versions[versionCounter]->url     = ( char* ) json_string_value( versionUrl );
			if ( versionCounter > 0 ) {
				homebrews[i].versions[versionCounter - 1]->next = homebrews[i].versions[versionCounter];
			}
			psvDebugScreenPrintf( "%s %s\n", homebrews[i].versions[versionCounter]->version, homebrews[i].versions[versionCounter]->url );
			versionCounter++;
		}
		psvDebugScreenPrintf( "\n");
	}
}

int main(int argc, char *argv[]) {
	psvDebugScreenInit();
	psvDebugScreenPrintf("JSON Sample v.1.0 by barooney\n\n");

	json_t *json;
    json_error_t error;

    size_t count;

    json = json_load_file("ux0:temp/sample.json", 0, &error);
    if ( ! json ) {
        psvDebugScreenPrintf("Error while loading %s:\n");
        psvDebugScreenPrintf("%s:\n", error.text);
    }

    if ( JSON_ARRAY != json_typeof( json ) ) {
		psvDebugScreenPrintf("Error: JSON is not an Array.\n");
    } else {
    	read_homebrews( json );
    }

	psvDebugScreenPrintf("This app will close in 10 seconds!\n");
	sceKernelDelayThread(10*1000*1000);

	sceKernelExitProcess(0);
	return 0;
}
