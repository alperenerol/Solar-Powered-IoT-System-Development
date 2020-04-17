<?php
# PHPlot Example: Simple line graph
require_once 'phplot.php';

$data = array();
$i = 0;

$handle = fopen("tempdata.txt", "r");
if ($handle) {
	while (!feof($handle)) {
		$zz=fgets($handle);
		$aa=str_getcsv($zz,' ');
		if (sizeof($aa)==1) {
			$data[] = array('', $i, $aa[0]);
			$i++;
		}
	}
}
fclose($handle);

$plot = new PHPlot(600, 400);
$plot->SetImageBorderType('plain');
$plot->SetPlotType('linepoints'); # area olur line olur istediğim şeyin ne lduğuna sonra karar veririm ama şekil burdan değişecek
$plot->SetDataType('data-data');
$plot->SetDataValues($data);
# Main plot title:
$plot->SetTitle('Temperature,C');
# Make sure Y axis starts at 0:
$plot->SetPlotAreaWorld(0, -10, 24, 50);

$plot->DrawGraph();

return $i

?>
