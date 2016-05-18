#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include "net.h"

static const char *URL_Changelog = "http://ttpsoft.weebly.com/uploads/3/8/6/0/38608823/updatelog.txt";


Net *net_init()
{
	CURL *curl = curl_easy_init();
	if (curl)
	{
		FILE *file = fopen("test.dat", "wb");
		curl_easy_setopt(curl, CURLOPT_URL, URL_Changelog);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
		CURLcode res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			fprintf(stderr, "CURL ERROR\n");
		}
		curl_easy_cleanup(curl);
		fclose(file);
	}
	Net *net = malloc(sizeof(Net));
	return net;
}

void net_close(Net *net)
{
	free(net);
}



void net_download(const char *url, const char *filename)
{
	//TODO: Linux compatibility
	
}
