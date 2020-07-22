function runtlccmd
% RUNTLCCMD - run tlc command (regenerate C code from .rtw file) for model caracterizacion
% This function will run the tlc command stored in the variable 
% "tlccmd" in tlccmd.mat, whose contents is as follows:
% 
% 	tlc
% 	-r
% 	C:\Documents and Settings\automatica\Mis documentos\Proyecto final control 2\caracterizacion_rtwin_win32\caracterizacion.rtw
% 	C:\Archivos de programa\MATLAB\R2012a\toolbox\rtw\targets\rtwin\rtwin\rtwin.tlc
% 	-OC:\Documents and Settings\automatica\Mis documentos\Proyecto final control 2\caracterizacion_rtwin_win32
% 	-IC:\Archivos de programa\MATLAB\R2012a\toolbox\rtw\targets\rtwin\rtwin
% 	-IC:\Archivos de programa\MATLAB\R2012a\toolbox\rtw\targets\rtwin\rtwin
% 	-IC:\Documents and Settings\automatica\Mis documentos\Proyecto final control 2\caracterizacion_rtwin_win32\tlc
% 	-IC:\Archivos de programa\MATLAB\R2012a\rtw\c\tlc\mw
% 	-IC:\Archivos de programa\MATLAB\R2012a\rtw\c\tlc\lib
% 	-IC:\Archivos de programa\MATLAB\R2012a\rtw\c\tlc\blocks
% 	-IC:\Archivos de programa\MATLAB\R2012a\rtw\c\tlc\fixpt
% 	-IC:\Archivos de programa\MATLAB\R2012a\stateflow\c\tlc
% 	-aFoldNonRolledExpr=1
% 	-aInlineInvariantSignals=0
% 	-aInlineParameters=0
% 	-aLocalBlockOutputs=1
% 	-aRollThreshold=5
% 	-aZeroInternalMemoryAtStartup=1
% 	-aZeroExternalMemoryAtStartup=1
% 	-aInitFltsAndDblsToZero=0
% 	-aForceBlockIOInitOptimize=0
% 	-aGenerateReport=0
% 	-aGenCodeOnly=0
% 	-aRTWVerbose=1
% 	-aIncludeHyperlinkInReport=0
% 	-aLaunchReport=0
% 	-aGenerateTraceInfo=0
% 	-aForceParamTrailComments=0
% 	-aGenerateComments=1
% 	-aIgnoreCustomStorageClasses=1
% 	-aIncHierarchyInIds=0
% 	-aMaxRTWIdLen=95
% 	-aShowEliminatedStatements=0
% 	-aIncDataTypeInIds=0
% 	-aInsertBlockDesc=0
% 	-aIgnoreTestpoints=0
% 	-aSimulinkBlockComments=1
% 	-aInlinedPrmAccess="Literals"
% 	-aTargetFcnLib="ansi_tfl_table_tmw.mat"
% 	-aIsPILTarget=0
% 	-aLogVarNameModifier="rt_"
% 	-aGenerateFullHeader=1
% 	-aExtMode=1
% 	-aExtModeStaticAlloc=0
% 	-aExtModeStaticAllocSize=1000000
% 	-aExtModeTransport=0
% 	-aExtModeTesting=0
% 	-aGenerateTraceInfo=0
% 	-aIgnoreTestpoints=0
% 	-aProtectedModelReferenceTarget=0
% 	-p10000

   disp('This function will be obsoleted in a future release.') 
   mdl = 'caracterizacion';

   sysopen = ~isempty(strmatch(mdl, find_system('type', 'block_diagram'), 'exact'));

   if ~sysopen

      disp([mfilename ': Error: model ' mdl ' is not open. Please open model ' mdl ' and then run ' mfilename ' again.']);

   else

      rtwprivate('rtwattic', 'setBuildDir', 'C:\Documents and Settings\automatica\Mis documentos\Proyecto final control 2\caracterizacion_rtwin_win32');
      rtwprivate('ec_set_replacement_flag', 'caracterizacion');
      load tlccmd.mat;
      savedpwd = pwd;
      cd ..;
      set_param(mdl,'MakeRTWSettingsObject', makertwObj);
      feval(tlccmd{:});
      set_param(mdl,'MakeRTWSettingsObject', []);
      rtwprivate rtwattic clean;
      cd(savedpwd);

   end
