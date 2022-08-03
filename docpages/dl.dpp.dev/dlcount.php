<?php
$githubApi = "https://api.github.com/repos/brainboxdotcc/dpp/releases";
$json = json_decode(
	file_get_contents(
		$githubApi,
		false,
		stream_context_create(
			[
				"http" => [
					"method" => "GET",
					"header" => "User-Agent: DPP/Website"
				]	
			]
		)
	)
);
$downloads = 0;
foreach ($json as $index => $release)
{
	$releaseDownloads = 0;
	foreach ($release->assets as $asset)
	{
		$releaseDownloads += $asset->download_count;
	}
	$downloads += $releaseDownloads;
}

header("Content-Type: image/svg+xml");
echo <<<IMG
<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" width="106" height="20" role="img" aria-label="downloads: {$downloads}"><title>downloads: {$downloads}</title><linearGradient id="s" x2="0" y2="100%"><stop offset="0" stop-color="#bbb" stop-opacity=".1"/><stop offset="1" stop-opacity=".1"/></linearGradient><clipPath id="r"><rect width="106" height="20" rx="3" fill="#fff"/></clipPath><g clip-path="url(#r)"><rect width="69" height="20" fill="#555"/><rect x="69" width="37" height="20" fill="#97ca00"/><rect width="106" height="20" fill="url(#s)"/></g><g fill="#fff" text-anchor="middle" font-family="Verdana,Geneva,DejaVu Sans,sans-serif" text-rendering="geometricPrecision" font-size="110"><text aria-hidden="true" x="355" y="150" fill="#010101" fill-opacity=".3" transform="scale(.1)" textLength="590">downloads</text><text x="355" y="140" transform="scale(.1)" fill="#fff" textLength="590">downloads</text><text aria-hidden="true" x="865" y="150" fill="#010101" fill-opacity=".3" transform="scale(.1)" textLength="270">{$downloads}</text><text x="865" y="140" transform="scale(.1)" fill="#fff" textLength="270">{$downloads}</text></g></svg>
IMG;

