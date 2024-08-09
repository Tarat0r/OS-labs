# Process priority
Find and compile the [linpack program](https://github.com/ereyes01/linpack) to evaluate the performance
of a computer (Flops) and test it in different operating modes of the OS:
- With different task priorities in the scheduler
- With and without binding to the processor
- With fixed CPU frequency
- Conduct several tests, compare the results by 3 sigma or other statistical criteria

## Result tables
<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-baqh{text-align:center;vertical-align:top}
.tg .tg-c3ow{border-color:inherit;text-align:center;vertical-align:top}
.tg .tg-0pky{border-color:inherit;text-align:left;vertical-align:top}
</style>
<table class="tg"><thead>
  <tr>
    <th class="tg-0pky"></th>
    <th class="tg-c3ow" colspan="3">Normal</th>
    <th class="tg-c3ow" colspan="3">Taskset</th>
    <th class="tg-c3ow" colspan="3">Boost</th>
    <th class="tg-baqh" colspan="3">Boost taskset</th>
  </tr></thead>
<tbody>
  <tr>
    <td class="tg-0pky"></td>
    <td class="tg-c3ow">DEAFAULT</td>
    <td class="tg-c3ow">NICE 19</td>
    <td class="tg-c3ow">NICE -20</td>
    <td class="tg-c3ow">DEAFAULT</td>
    <td class="tg-c3ow">NICE 19</td>
    <td class="tg-c3ow">NICE -20</td>
    <td class="tg-c3ow">DEAFAULT</td>
    <td class="tg-c3ow">NICE 19</td>
    <td class="tg-c3ow">NICE -20</td>
    <td class="tg-baqh">DEAFAULT</td>
    <td class="tg-baqh">NICE 19</td>
    <td class="tg-baqh">NICE -20</td>
  </tr>
  <tr>
    <td class="tg-0pky">Lower limit</td>
    <td class="tg-c3ow">4250260.378</td>
    <td class="tg-c3ow">1933922.233</td>
    <td class="tg-c3ow">1860926.648</td>
    <td class="tg-c3ow">3381578.184</td>
    <td class="tg-c3ow">2372604.556</td>
    <td class="tg-c3ow">2383171.253</td>
    <td class="tg-c3ow">3534556.538</td>
    <td class="tg-c3ow">1405386.676</td>
    <td class="tg-c3ow">1874201.689</td>
    <td class="tg-baqh">2314689.559</td>
    <td class="tg-baqh">3308884.039</td>
    <td class="tg-baqh">1700442.695</td>
  </tr>
  <tr>
    <td class="tg-0pky">Upper limit</td>
    <td class="tg-c3ow">11595052.066</td>
    <td class="tg-c3ow">10322023.212</td>
    <td class="tg-c3ow">11984441.796</td>
    <td class="tg-c3ow">12032055.372</td>
    <td class="tg-c3ow">12152099.777</td>
    <td class="tg-c3ow">12077915.303</td>
    <td class="tg-c3ow">12093984.018</td>
    <td class="tg-c3ow">12285723.435</td>
    <td class="tg-c3ow">12366146.977</td>
    <td class="tg-baqh">12729932.663</td>
    <td class="tg-baqh">12516609.739</td>
    <td class="tg-baqh">12279686.860</td>
  </tr>
</tbody></table>

<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-baqh{text-align:center;vertical-align:top}
.tg .tg-c3ow{border-color:inherit;text-align:center;vertical-align:top}
.tg .tg-0pky{border-color:inherit;text-align:left;vertical-align:top}
</style>
<table class="tg"><thead>
  <tr>
    <th class="tg-c3ow"></th>
    <th class="tg-c3ow" colspan="3">Normal</th>
    <th class="tg-c3ow" colspan="3">Taskset</th>
    <th class="tg-c3ow" colspan="3">Boost</th>
    <th class="tg-baqh" colspan="3">Boost taskset</th>
  </tr></thead>
<tbody>
  <tr>
    <td class="tg-c3ow"></td>
    <td class="tg-c3ow">DEAFAULT</td>
    <td class="tg-c3ow">NICE 19</td>
    <td class="tg-c3ow">NICE -20</td>
    <td class="tg-c3ow">DEAFAULT</td>
    <td class="tg-c3ow">NICE 19</td>
    <td class="tg-c3ow">NICE -20</td>
    <td class="tg-c3ow">DEAFAULT</td>
    <td class="tg-c3ow">NICE 19</td>
    <td class="tg-c3ow">NICE -20</td>
    <td class="tg-baqh">DEAFAULT</td>
    <td class="tg-baqh">NICE 19</td>
    <td class="tg-baqh">NICE -20</td>
  </tr>
  <tr>
    <td class="tg-0pky">Mathematical expectation</td>
    <td class="tg-c3ow">7922656.222</td>
    <td class="tg-c3ow">6127972.722</td>
    <td class="tg-c3ow">6922684.222</td>
    <td class="tg-c3ow">7706816.778</td>
    <td class="tg-c3ow">7262352.167</td>
    <td class="tg-c3ow">7230543.278</td>
    <td class="tg-c3ow">7814270.278</td>
    <td class="tg-c3ow">6845555.056</td>
    <td class="tg-c3ow">7120174.333</td>
    <td class="tg-baqh">7522311.111</td>
    <td class="tg-baqh">7912746.889</td>
    <td class="tg-baqh">6990064.778</td>
  </tr>
  <tr>
    <td class="tg-0pky">Mean square deviation</td>
    <td class="tg-c3ow">1224131.948</td>
    <td class="tg-c3ow">1398016.830</td>
    <td class="tg-c3ow">1687252.525</td>
    <td class="tg-c3ow">1441746.198</td>
    <td class="tg-c3ow">1629915.870</td>
    <td class="tg-c3ow">1615790.675</td>
    <td class="tg-c3ow">1426571.247</td>
    <td class="tg-c3ow">1813389.460</td>
    <td class="tg-c3ow">1748657.548</td>
    <td class="tg-baqh">1735873.851</td>
    <td class="tg-baqh">1534620.950</td>
    <td class="tg-baqh">1763207.361</td>
  </tr>
</tbody></table>

As can be seen from the tables, all values ​​belong to intervals and the 3 sigma rule is satisfied.

## cpupower
<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-c3ow{border-color:inherit;text-align:center;vertical-align:top}
.tg .tg-0pky{border-color:inherit;text-align:left;vertical-align:top}
</style>
<table class="tg"><thead>
  <tr>
    <th class="tg-0pky"></th>
    <th class="tg-c3ow" colspan="3">800Mhz</th>
  </tr></thead>
<tbody>
  <tr>
    <td class="tg-0pky"></td>
    <td class="tg-c3ow">DEAFAULT</td>
    <td class="tg-c3ow">NICE 19</td>
    <td class="tg-c3ow">NICE -20</td>
  </tr>
  <tr>
    <td class="tg-0pky">Lower limit</td>
    <td class="tg-c3ow">1654431.461</td>
    <td class="tg-c3ow">1664220.706</td>
    <td class="tg-c3ow">1722674.390</td>
  </tr>
  <tr>
    <td class="tg-0pky">Upper limit</td>
    <td class="tg-c3ow">1903069.317</td>
    <td class="tg-c3ow">1814039.850</td>
    <td class="tg-c3ow">1811890.277</td>
  </tr>
  <tr>
    <td class="tg-0pky">Mathematical expectation</td>
    <td class="tg-c3ow">1778750.389</td>
    <td class="tg-c3ow">1739130.278</td>
    <td class="tg-c3ow">1767282.333</td>
  </tr>
  <tr>
    <td class="tg-0pky">Mean square deviation</td>
    <td class="tg-c3ow">41439.643</td>
    <td class="tg-c3ow">24969.857</td>
    <td class="tg-c3ow">14869.314</td>
  </tr>
</tbody></table>

Since the laptop has a default processor frequency almost maximum,
I did a test with a frequency of 800Mhz and it is clear that there is a big difference
between the performance in the tests. Otherwise, nice does not change the result very much because the laptop was not loaded during the tests. On average, the highest values ​​​​were obtained when the test was launched without
additional settings and we can conclude that with a small
load, ubuntu works faster than when we change the priority and
previse the process to the kernel.