<?php 
	$xml = simplexml_load_string(file_get_contents('NppFTP.xml'));
	
	$json = json_encode($xml);

	$array = json_decode($json,TRUE);

	$profiles = $array['Profiles']['Profile'];

	echo implode(';', array_keys($profiles[0]['@attributes']))."\n";

	foreach ($profiles as $profile) {
		$attributes = $profile['@attributes'];

		$attributes['password'] = shell_exec ('./npp_ed --d '.$attributes['password']);

		echo implode(';', $attributes)."\n";

		//print_r($profile);
	}
?>