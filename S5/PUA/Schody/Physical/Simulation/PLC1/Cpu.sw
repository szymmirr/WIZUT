<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio Version=3.0.90.38 SP20?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1" />
  <TaskClass Name="Cyclic#2" />
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4">
    <Task Name="Zarowa" Source="Zarowa.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="schody" Source="schody.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="Ppoz" Source="Ppoz.prg" Memory="UserROM" Language="IEC" Debugging="true" />
  </TaskClass>
  <DataObjects />
  <NcDataObjects />
  <VcDataObjects />
  <Binaries />
  <Libraries>
    <LibraryObject Name="AsIecCon" Source="Libraries.AsIecCon.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="astime" Source="Libraries.astime.lby" Memory="UserROM" Language="Binary" Debugging="true" />
  </Libraries>
</SwConfiguration>