typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long    undefined5;
typedef unsigned long    undefined6;
typedef unsigned long    undefined7;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct ChunkTransportState ChunkTransportState, *PChunkTransportState;

typedef struct ChunkTransportStateEntry ChunkTransportStateEntry, *PChunkTransportStateEntry;

typedef struct MotionConn MotionConn, *PMotionConn;

typedef struct TupleChunkListItemData TupleChunkListItemData, *PTupleChunkListItemData;

typedef struct TupleChunkListItemData * TupleChunkListItem;

typedef short int16;

typedef struct List List, *PList;

typedef struct SliceTable SliceTable, *PSliceTable;

typedef struct EState EState, *PEState;

typedef struct mpp_fd_set mpp_fd_set, *Pmpp_fd_set;

typedef struct Slice Slice, *PSlice;

typedef ulong uint64;

typedef struct ICBufferList ICBufferList, *PICBufferList;

typedef uint uint32;

typedef struct ICBuffer ICBuffer, *PICBuffer;

typedef uchar uint8;

typedef ushort uint16;

typedef int int32;

typedef enum MotionConnState {
    mcsAccepted=1,
    mcsConnecting=3,
    mcsEosSent=7,
    mcsNull=0,
    mcsRecvRegMsg=4,
    mcsSendRegMsg=5,
    mcsSetupOutgoingConnection=2,
    mcsStarted=6
} MotionConnState;

struct icpkthdr { /* DWARF DIE: 59863d */
    int32 motNodeId;
    int32 srcPid;
    int32 srcListenerPort;
    int32 dstPid;
    int32 dstListenerPort;
    int32 sessionId;
    uint32 icId;
    int32 recvSliceIndex;
    int32 sendSliceIndex;
    int32 srcContentId;
    int32 dstContentId;
    uint32 crc;
    int32 flags;
    int32 len;
    uint32 seq;
    uint32 extraSeq;
};


typedef struct CdbProcess CdbProcess, *PCdbProcess;

typedef struct sockaddr_storage sockaddr_storage, *Psockaddr_storage;

typedef uint __socklen_t;

typedef __socklen_t socklen_t;

typedef struct TupleRemapper TupleRemapper, *PTupleRemapper;

typedef enum NodeTag {
    T_AOCSPath=507,
    T_A_ArrayExpr=908,
    T_A_Const=903,
    T_A_Expr=900,
    T_A_Indices=906,
    T_A_Indirection=907,
    T_A_Star=905,
    T_AccessPriv=930,
    T_Agg=-122,
    T_AggState=-22,
    T_Aggref=306,
    T_AggrefExprState=403,
    T_Alias=300,
    T_AllocSetContext=601,
    T_AlterDatabaseSetStmt=765,
    T_AlterDatabaseStmt=764,
    T_AlterDefaultPrivilegesStmt=712,
    T_AlterDomainStmt=708,
    T_AlterEnumStmt=785,
    T_AlterEventTrigStmt=803,
    T_AlterExtensionContentsStmt=801,
    T_AlterExtensionStmt=800,
    T_AlterFdwStmt=789,
    T_AlterForeignServerStmt=791,
    T_AlterFunctionStmt=727,
    T_AlterObjectSchemaStmt=778,
    T_AlterOpFamilyStmt=771,
    T_AlterOwnerStmt=779,
    T_AlterPartitionCmd=814,
    T_AlterPartitionId=813,
    T_AlterQueueStmt=754,
    T_AlterResourceGroupStmt=758,
    T_AlterRoleSetStmt=766,
    T_AlterRoleStmt=751,
    T_AlterSeqStmt=744,
    T_AlterSystemStmt=806,
    T_AlterTSConfigurationStmt=787,
    T_AlterTSDictionaryStmt=786,
    T_AlterTableCmd=707,
    T_AlterTableMoveAllStmt=796,
    T_AlterTableSpaceOptionsStmt=795,
    T_AlterTableStmt=706,
    T_AlterTypeStmt=822,
    T_AlterUserMappingStmt=793,
    T_AlternativeSubPlan=318,
    T_AlternativeSubPlanState=410,
    T_Append=105,
    T_AppendOnlyPath=506,
    T_AppendPath=518,
    T_AppendRelInfo=530,
    T_AppendState=-51,
    T_ArrayCoerceExpr=323,
    T_ArrayCoerceExprState=414,
    T_ArrayExpr=329,
    T_ArrayExprState=418,
    T_ArrayRef=308,
    T_ArrayRefExprState=405,
    T_AssertOp=-109,
    T_AssertOpState=-9,
    T_BaseBackupCmd=941,
    T_BitString=654,
    T_BitmapAnd=109,
    T_BitmapAndPath=511,
    T_BitmapAndState=-47,
    T_BitmapHeapPath=510,
    T_BitmapHeapScan=119,
    T_BitmapHeapScanState=-37,
    T_BitmapIndexScan=117,
    T_BitmapIndexScanState=-39,
    T_BitmapOr=110,
    T_BitmapOrPath=512,
    T_BitmapOrState=-46,
    T_BoolExpr=315,
    T_BoolExprState=408,
    T_BooleanTest=336,
    T_CaseExpr=326,
    T_CaseExprState=416,
    T_CaseTestExpr=328,
    T_CaseWhen=327,
    T_CaseWhenState=417,
    T_CdbExplain_StatHdr=1000,
    T_CdbMotionPath=580,
    T_CdbProcess=17,
    T_CdbRelColumnInfo=582,
    T_CheckPointStmt=762,
    T_ClosePortalStmt=713,
    T_ClusterStmt=714,
    T_CoalesceExpr=332,
    T_CoalesceExprState=421,
    T_CoerceToDomain=337,
    T_CoerceToDomainState=425,
    T_CoerceToDomainValue=338,
    T_CoerceViaIO=322,
    T_CoerceViaIOState=413,
    T_CollateClause=911,
    T_CollateExpr=325,
    T_ColumnDef=917,
    T_ColumnRef=901,
    T_ColumnReferenceStorageDirective=939,
    T_CommentStmt=723,
    T_CommonTableExpr=938,
    T_CompositeTypeStmt=782,
    T_Const=304,
    T_Constraint=919,
    T_ConstraintsSetStmt=760,
    T_ConvertRowtypeExpr=324,
    T_ConvertRowtypeExprState=415,
    T_CookedConstraint=962,
    T_CopyIntoClause=346,
    T_CopyStmt=715,
    T_CreateCastStmt=768,
    T_CreateConversionStmt=767,
    T_CreateDomainStmt=737,
    T_CreateEnumStmt=783,
    T_CreateEventTrigStmt=802,
    T_CreateExtensionStmt=799,
    T_CreateExternalStmt=719,
    T_CreateFdwStmt=788,
    T_CreateFileSpaceStmt=816,
    T_CreateForeignServerStmt=790,
    T_CreateForeignTableStmt=798,
    T_CreateFunctionStmt=726,
    T_CreateOpClassItem=931,
    T_CreateOpClassStmt=769,
    T_CreateOpFamilyStmt=770,
    T_CreatePLangStmt=749,
    T_CreateQueueStmt=753,
    T_CreateRangeStmt=784,
    T_CreateReplicationSlotCmd=942,
    T_CreateResourceGroupStmt=756,
    T_CreateRoleStmt=750,
    T_CreateSchemaStmt=763,
    T_CreateSeqStmt=743,
    T_CreateStmt=716,
    T_CreateTableAsStmt=742,
    T_CreateTableSpaceStmt=776,
    T_CreateTrigStmt=748,
    T_CreateUserMappingStmt=792,
    T_CreatedbStmt=738,
    T_CteScan=126,
    T_CteScanState=-30,
    T_CurrentOfExpr=340,
    T_CursorPosInfo=20,
    T_DML=-112,
    T_DMLActionExpr=351,
    T_DMLState=-12,
    T_DeallocateStmt=774,
    T_DeclareCursorStmt=775,
    T_DefElem=920,
    T_DefineStmt=720,
    T_DeleteStmt=703,
    T_DenyLoginInterval=820,
    T_DenyLoginPoint=821,
    T_DiscardStmt=747,
    T_DistinctExpr=312,
    T_DistributedBy=350,
    T_DistributionKey=583,
    T_DoStmt=728,
    T_DomainConstraintState=426,
    T_DropFileSpaceStmt=818,
    T_DropOwnedStmt=780,
    T_DropQueueStmt=755,
    T_DropReplicationSlotCmd=943,
    T_DropResourceGroupStmt=757,
    T_DropRoleStmt=752,
    T_DropStmt=721,
    T_DropTableSpaceStmt=777,
    T_DropUserMappingStmt=794,
    T_DropdbStmt=739,
    T_DynamicBitmapHeapScan=120,
    T_DynamicBitmapHeapScanState=-36,
    T_DynamicBitmapIndexScan=118,
    T_DynamicBitmapIndexScanState=-38,
    T_DynamicIndexScan=115,
    T_DynamicIndexScanState=-41,
    T_DynamicSeqScan=112,
    T_DynamicSeqScanState=-44,
    T_EState=15,
    T_EquivalenceClass=523,
    T_EquivalenceMember=524,
    T_EventTriggerData=951,
    T_ExecuteStmt=773,
    T_ExpandStmtSpec=824,
    T_ExplainStmt=741,
    T_Expr=302,
    T_ExprContext=11,
    T_ExprState=400,
    T_ExtProtocolData=959,
    T_ExtProtocolValidatorData=960,
    T_ExtTableTypeDesc=718,
    T_ExternalPath=508,
    T_ExternalScan=113,
    T_ExternalScanState=-43,
    T_FdwRoutine=956,
    T_FetchStmt=724,
    T_FieldSelect=319,
    T_FieldSelectState=411,
    T_FieldStore=320,
    T_FieldStoreState=412,
    T_FileSpaceEntry=817,
    T_Float=652,
    T_Flow=347,
    T_ForeignPath=517,
    T_ForeignScan=-128,
    T_ForeignScanState=-28,
    T_FormatterData=958,
    T_FromExpr=344,
    T_FuncCall=904,
    T_FuncExpr=309,
    T_FuncExprState=406,
    T_FuncWithArgs=929,
    T_FunctionParameter=933,
    T_FunctionScan=123,
    T_FunctionScanState=-33,
    T_GenericExprState=401,
    T_GpPolicy=1001,
    T_GrantRoleStmt=711,
    T_GrantStmt=710,
    T_GroupId=349,
    T_Grouping=348,
    T_GroupingClause=924,
    T_GroupingFunc=925,
    T_GroupingFuncExprState=427,
    T_Hash=-119,
    T_HashJoin=-125,
    T_HashJoinState=-25,
    T_HashPath=515,
    T_HashState=-19,
    T_IdentifySystemCmd=940,
    T_IndexElem=918,
    T_IndexInfo=10,
    T_IndexOnlyScan=116,
    T_IndexOnlyScanState=-40,
    T_IndexOptInfo=503,
    T_IndexPath=509,
    T_IndexScan=114,
    T_IndexScanState=-42,
    T_IndexStmt=725,
    T_InheritPartitionCmd=815,
    T_InlineCodeBlock=955,
    T_InsertStmt=702,
    T_IntList=657,
    T_Integer=651,
    T_IntoClause=345,
    T_Invalid=0,
    T_Join=102,
    T_JoinExpr=343,
    T_JoinState=-54,
    T_JunkFilter=13,
    T_LateralJoinInfo=529,
    T_Limit=-116,
    T_LimitState=-16,
    T_List=656,
    T_ListenStmt=732,
    T_LoadStmt=736,
    T_LockRows=-117,
    T_LockRowsState=-17,
    T_LockStmt=759,
    T_LockingClause=934,
    T_Material=-124,
    T_MaterialPath=521,
    T_MaterialState=-24,
    T_MemoryAccount=602,
    T_MemoryContext=600,
    T_MergeAppend=106,
    T_MergeAppendPath=519,
    T_MergeAppendState=-50,
    T_MergeJoin=-126,
    T_MergeJoinState=-26,
    T_MergePath=514,
    T_MinMaxAggInfo=532,
    T_MinMaxExpr=333,
    T_MinMaxExprState=422,
    T_ModifyTable=104,
    T_ModifyTableState=-52,
    T_Motion=-115,
    T_MotionState=-15,
    T_NamedArgExpr=310,
    T_NestLoop=-127,
    T_NestLoopParam=-106,
    T_NestLoopState=-27,
    T_NestPath=513,
    T_NotifyStmt=731,
    T_Null=655,
    T_NullIfExpr=313,
    T_NullTest=335,
    T_NullTestState=424,
    T_OidAssignment=24,
    T_OidList=658,
    T_OpExpr=311,
    T_Param=305,
    T_ParamPathInfo=504,
    T_ParamRef=902,
    T_PartBoundExpr=354,
    T_PartBoundExprState=430,
    T_PartBoundInclusionExpr=355,
    T_PartBoundInclusionExprState=431,
    T_PartBoundOpenExpr=356,
    T_PartBoundOpenExprState=432,
    T_PartDefaultExpr=353,
    T_PartDefaultExprState=429,
    T_PartListNullTestExpr=358,
    T_PartListNullTestExprState=434,
    T_PartListRuleExpr=357,
    T_PartListRuleExprState=433,
    T_PartSelectedExpr=352,
    T_PartSelectedExprState=428,
    T_Partition=533,
    T_PartitionBoundSpec=810,
    T_PartitionBy=807,
    T_PartitionElem=808,
    T_PartitionNode=535,
    T_PartitionRangeItem=809,
    T_PartitionRule=534,
    T_PartitionSelector=-108,
    T_PartitionSelectorPath=581,
    T_PartitionSelectorState=-8,
    T_PartitionSpec=811,
    T_PartitionState=22,
    T_PartitionValuesSpec=812,
    T_Path=505,
    T_PathKey=525,
    T_PgPartRule=536,
    T_PlaceHolderInfo=531,
    T_PlaceHolderVar=527,
    T_Plan=100,
    T_PlanInvalItem=-104,
    T_PlanRowMark=-105,
    T_PlanState=-56,
    T_Plan_End=-107,
    T_Plan_Start=103,
    T_PlannedStmt=701,
    T_PlannerGlobal=501,
    T_PlannerInfo=500,
    T_PlannerParamItem=538,
    T_PrepareStmt=772,
    T_PrivGrantee=928,
    T_ProjectionInfo=12,
    T_Query=700,
    T_QueryDispatchDesc=23,
    T_RangeFunction=915,
    T_RangeSubselect=914,
    T_RangeTblEntry=921,
    T_RangeTblFunction=922,
    T_RangeTblRef=342,
    T_RangeVar=301,
    T_ReassignOwnedStmt=781,
    T_RecursiveUnion=107,
    T_RecursiveUnionState=-49,
    T_RefreshMatViewStmt=804,
    T_ReindexStmt=761,
    T_RelOptInfo=502,
    T_RelabelType=321,
    T_RenameStmt=729,
    T_Repeat=-113,
    T_RepeatState=-13,
    T_ReplicaIdentityStmt=805,
    T_ResTarget=909,
    T_RestrictInfo=526,
    T_Result=103,
    T_ResultPath=520,
    T_ResultRelInfo=14,
    T_ResultState=-53,
    T_ReturnSetInfo=952,
    T_RowCompareExpr=331,
    T_RowCompareExprState=420,
    T_RowExpr=330,
    T_RowExprState=419,
    T_RowMarkClause=935,
    T_RowTrigger=-110,
    T_RowTriggerState=-10,
    T_RuleStmt=730,
    T_ScalarArrayOpExpr=314,
    T_ScalarArrayOpExprState=407,
    T_Scan=101,
    T_ScanState=-55,
    T_SecLabelStmt=797,
    T_SegfileMapNode=537,
    T_SelectStmt=705,
    T_SelectedParts=961,
    T_SeqScan=111,
    T_SeqScanState=-45,
    T_Sequence=108,
    T_SequenceState=-48,
    T_SerializedParamExternData=-6,
    T_SetDistributionCmd=823,
    T_SetOp=-118,
    T_SetOpState=-18,
    T_SetOperationStmt=709,
    T_SetToDefault=339,
    T_ShareInputScan=-114,
    T_ShareInputScanState=-14,
    T_ShareNodeEntry=21,
    T_SingleRowErrorDesc=717,
    T_Slice=18,
    T_SliceTable=19,
    T_Sort=-123,
    T_SortBy=912,
    T_SortGroupClause=926,
    T_SortState=-23,
    T_SpecialJoinInfo=528,
    T_SplitUpdate=-111,
    T_SplitUpdateState=-11,
    T_StartReplicationCmd=944,
    T_StreamBitmap=957,
    T_String=653,
    T_SubLink=316,
    T_SubPlan=317,
    T_SubPlanState=409,
    T_SubqueryScan=122,
    T_SubqueryScanState=-34,
    T_TIDBitmap=954,
    T_TableFunctionScan=124,
    T_TableFunctionState=-32,
    T_TableLikeClause=932,
    T_TableOidInfo=359,
    T_TableValueExpr=819,
    T_TargetEntry=341,
    T_TidPath=516,
    T_TidScan=121,
    T_TidScanState=-35,
    T_TimeLineHistoryCmd=945,
    T_TransactionStmt=734,
    T_TriggerData=950,
    T_TruncateStmt=722,
    T_TupleDescNode=-7,
    T_TupleTableSlot=16,
    T_TypeCast=910,
    T_TypeName=916,
    T_Unique=-120,
    T_UniquePath=522,
    T_UniqueState=-20,
    T_UnlistenStmt=733,
    T_UpdateStmt=704,
    T_VacuumStmt=740,
    T_Value=650,
    T_ValuesScan=125,
    T_ValuesScanState=-31,
    T_Var=303,
    T_VariableSetStmt=745,
    T_VariableShowStmt=746,
    T_ViewStmt=735,
    T_WholeRowVarExprState=402,
    T_WindowAgg=-121,
    T_WindowAggState=-21,
    T_WindowClause=927,
    T_WindowDef=913,
    T_WindowFunc=307,
    T_WindowFuncExprState=404,
    T_WindowObjectData=953,
    T_WithCheckOption=923,
    T_WithClause=937,
    T_WorkTableScan=127,
    T_WorkTableScanState=-29,
    T_XmlExpr=334,
    T_XmlExprState=423,
    T_XmlSerialize=936
} NodeTag;

typedef struct ListCell ListCell, *PListCell;

typedef enum ScanDirection {
    BackwardScanDirection=-1,
    ForwardScanDirection=1,
    NoMovementScanDirection=0
} ScanDirection;

typedef struct SnapshotData SnapshotData, *PSnapshotData;

typedef struct RelationData RelationData, *PRelationData;

typedef struct RelationData * Relation;

typedef struct HeapTupleData HeapTupleData, *PHeapTupleData;

typedef struct HeapTupleData * HeapTuple;

typedef int Buffer;

typedef struct SnapshotData * Snapshot;

typedef struct PlannedStmt PlannedStmt, *PPlannedStmt;

typedef struct JunkFilter JunkFilter, *PJunkFilter;

typedef uint32 CommandId;

typedef struct ResultRelInfo ResultRelInfo, *PResultRelInfo;

typedef struct PartitionNode PartitionNode, *PPartitionNode;

typedef struct TupleTableSlot TupleTableSlot, *PTupleTableSlot;

typedef struct ParamListInfoData ParamListInfoData, *PParamListInfoData;

typedef struct ParseState ParseState, *PParseState;

typedef struct Node Node, *PNode;

typedef struct ColumnRef ColumnRef, *PColumnRef;

typedef struct ParamRef ParamRef, *PParamRef;

typedef struct Param Param, *PParam;

typedef uint Oid;

typedef struct ParamListInfoData * ParamListInfo;

typedef struct ParamExecData ParamExecData, *PParamExecData;

typedef struct MemoryContextData MemoryContextData, *PMemoryContextData;

typedef struct MemoryContextData * MemoryContext;

typedef struct ExprContext ExprContext, *PExprContext;

typedef struct CdbDispatcherState CdbDispatcherState, *PCdbDispatcherState;

typedef struct CdbExplain_ShowStatCtx CdbExplain_ShowStatCtx, *PCdbExplain_ShowStatCtx;

typedef struct PartitionState PartitionState, *PPartitionState;

typedef struct DynamicTableScanInfo DynamicTableScanInfo, *PDynamicTableScanInfo;

typedef enum GangType {
    GANGTYPE_ENTRYDB_READER=1,
    GANGTYPE_PRIMARY_READER=3,
    GANGTYPE_PRIMARY_WRITER=4,
    GANGTYPE_SINGLETON_READER=2,
    GANGTYPE_UNALLOCATED=0
} GangType;

typedef struct DirectDispatchInfo DirectDispatchInfo, *PDirectDispatchInfo;

typedef struct Gang Gang, *PGang;

typedef struct Bitmapset Bitmapset, *PBitmapset;

typedef enum ICBufferListType {
    ICBufferListType_Primary=0,
    ICBufferListType_Secondary=1,
    ICBufferListType_UNDEFINED=2
} ICBufferListType;

typedef struct ICBufferLink ICBufferLink, *PICBufferLink;

typedef ushort sa_family_t;

typedef union anon_union_for_data anon_union_for_data, *Panon_union_for_data;

typedef struct RelFileNode RelFileNode, *PRelFileNode;

typedef struct SMgrRelationData SMgrRelationData, *PSMgrRelationData;

typedef int BackendId;

typedef uint32 SubTransactionId;

typedef struct FormData_pg_class FormData_pg_class, *PFormData_pg_class;

typedef struct FormData_pg_class * Form_pg_class;

typedef struct tupleDesc tupleDesc, *PtupleDesc;

typedef struct tupleDesc * TupleDesc;

typedef struct LockInfoData LockInfoData, *PLockInfoData;

typedef struct RuleLock RuleLock, *PRuleLock;

typedef struct TriggerDesc TriggerDesc, *PTriggerDesc;

typedef struct GpPolicy GpPolicy, *PGpPolicy;

typedef struct varlena varlena, *Pvarlena;

typedef struct varlena bytea;

typedef struct FormData_pg_index FormData_pg_index, *PFormData_pg_index;

typedef struct FormData_pg_index * Form_pg_index;

typedef struct FormData_pg_am FormData_pg_am, *PFormData_pg_am;

typedef struct FormData_pg_am * Form_pg_am;

typedef struct RelationAmInfo RelationAmInfo, *PRelationAmInfo;

typedef Oid regproc;

typedef regproc RegProcedure;

typedef struct FmgrInfo FmgrInfo, *PFmgrInfo;

typedef long int64;

typedef int64 Datum;

typedef struct FunctionCallInfoData FunctionCallInfoData, *PFunctionCallInfoData;

typedef struct FunctionCallInfoData * FunctionCallInfo;

typedef struct FdwRoutine FdwRoutine, *PFdwRoutine;

typedef struct ForeignScan ForeignScan, *PForeignScan;

typedef struct PlannerInfo PlannerInfo, *PPlannerInfo;

typedef struct RelOptInfo RelOptInfo, *PRelOptInfo;

typedef struct ForeignPath ForeignPath, *PForeignPath;

typedef struct ForeignScanState ForeignScanState, *PForeignScanState;

typedef struct Query Query, *PQuery;

typedef struct RangeTblEntry RangeTblEntry, *PRangeTblEntry;

typedef struct ModifyTable ModifyTable, *PModifyTable;

typedef uint Index;

typedef struct ModifyTableState ModifyTableState, *PModifyTableState;

typedef struct ExplainState ExplainState, *PExplainState;

typedef uint32 BlockNumber;

typedef struct FormData_pg_appendonly FormData_pg_appendonly, *PFormData_pg_appendonly;

typedef struct FormData_pg_appendonly * Form_pg_appendonly;

typedef struct PgStat_TableStatus PgStat_TableStatus, *PPgStat_TableStatus;

typedef struct ItemPointerData ItemPointerData, *PItemPointerData;

typedef struct HeapTupleHeaderData HeapTupleHeaderData, *PHeapTupleHeaderData;

typedef struct HeapTupleHeaderData * HeapTupleHeader;

typedef uint32 TransactionId;

typedef struct DistributedSnapshotWithLocalMapping DistributedSnapshotWithLocalMapping, *PDistributedSnapshotWithLocalMapping;

typedef enum CmdType {
    CMD_DELETE=4,
    CMD_INSERT=3,
    CMD_NOTHING=6,
    CMD_SELECT=1,
    CMD_UNKNOWN=0,
    CMD_UPDATE=2,
    CMD_UTILITY=5
} CmdType;

typedef enum PlanGenerator {
    PLANGEN_OPTIMIZER=1,
    PLANGEN_PLANNER=0
} PlanGenerator;

typedef struct Plan Plan, *PPlan;

typedef struct IntoClause IntoClause, *PIntoClause;

typedef struct CopyIntoClause CopyIntoClause, *PCopyIntoClause;

typedef char int8;

typedef int16 AttrNumber;

typedef Relation * RelationPtr;

typedef struct IndexInfo IndexInfo, *PIndexInfo;

typedef struct Instrumentation Instrumentation, *PInstrumentation;

typedef struct ProjectionInfo ProjectionInfo, *PProjectionInfo;

typedef struct MemTupleBinding MemTupleBinding, *PMemTupleBinding;

typedef struct AppendOnlyInsertDescData AppendOnlyInsertDescData, *PAppendOnlyInsertDescData;

typedef struct AOCSInsertDescData AOCSInsertDescData, *PAOCSInsertDescData;

typedef struct ExternalInsertDescData ExternalInsertDescData, *PExternalInsertDescData;

typedef void * RelationDeleteDesc;

typedef void * RelationUpdateDesc;

typedef struct AttrMap AttrMap, *PAttrMap;

typedef struct HTAB HTAB, *PHTAB;

typedef struct BulkInsertStateData BulkInsertStateData, *PBulkInsertStateData;

typedef struct BulkInsertStateData * BulkInsertState;

typedef ulong size_t;

typedef size_t Size;

typedef struct Partition Partition, *PPartition;

typedef struct PartitionRule PartitionRule, *PPartitionRule;

typedef struct MemTupleData MemTupleData, *PMemTupleData;

typedef struct MemTupleData * MemTuple;

typedef struct CommonTableExpr CommonTableExpr, *PCommonTableExpr;

typedef enum ParseExprKind {
    EXPR_KIND_ALTER_COL_TRANSFORM=30,
    EXPR_KIND_CHECK_CONSTRAINT=24,
    EXPR_KIND_COLUMN_DEFAULT=26,
    EXPR_KIND_DISTINCT_ON=19,
    EXPR_KIND_DOMAIN_CHECK=25,
    EXPR_KIND_EXECUTE_PARAMETER=31,
    EXPR_KIND_FILTER=8,
    EXPR_KIND_FROM_FUNCTION=5,
    EXPR_KIND_FROM_SUBSELECT=4,
    EXPR_KIND_FUNCTION_DEFAULT=27,
    EXPR_KIND_GROUP_BY=17,
    EXPR_KIND_HAVING=7,
    EXPR_KIND_INDEX_EXPRESSION=28,
    EXPR_KIND_INDEX_PREDICATE=29,
    EXPR_KIND_INSERT_TARGET=14,
    EXPR_KIND_JOIN_ON=2,
    EXPR_KIND_JOIN_USING=3,
    EXPR_KIND_LIMIT=20,
    EXPR_KIND_NONE=0,
    EXPR_KIND_OFFSET=21,
    EXPR_KIND_ORDER_BY=18,
    EXPR_KIND_OTHER=1,
    EXPR_KIND_PARTITION_EXPRESSION=33,
    EXPR_KIND_RETURNING=22,
    EXPR_KIND_SCATTER_BY=34,
    EXPR_KIND_SELECT_TARGET=13,
    EXPR_KIND_TRIGGER_WHEN=32,
    EXPR_KIND_UPDATE_SOURCE=15,
    EXPR_KIND_UPDATE_TARGET=16,
    EXPR_KIND_VALUES=23,
    EXPR_KIND_WHERE=6,
    EXPR_KIND_WINDOW_FRAME_RANGE=11,
    EXPR_KIND_WINDOW_FRAME_ROWS=12,
    EXPR_KIND_WINDOW_ORDER=10,
    EXPR_KIND_WINDOW_PARTITION=9
} ParseExprKind;

typedef struct LockingClause LockingClause, *PLockingClause;

typedef struct Expr Expr, *PExpr;

typedef enum ParamKind {
    PARAM_EXEC=1,
    PARAM_EXEC_REMOTE=2,
    PARAM_EXTERN=0,
    PARAM_SUBLINK=3
} ParamKind;

typedef struct ParamExternData ParamExternData, *PParamExternData;

typedef struct MemoryContextMethods MemoryContextMethods, *PMemoryContextMethods;

typedef struct ExprContext_CB ExprContext_CB, *PExprContext_CB;

typedef struct CdbDispatchResults CdbDispatchResults, *PCdbDispatchResults;

typedef struct StringInfoData StringInfoData, *PStringInfoData;

typedef struct timeval timeval, *Ptimeval;

typedef struct timeval instr_time;

typedef struct CdbExplain_SliceSummary CdbExplain_SliceSummary, *PCdbExplain_SliceSummary;

typedef struct PartitionAccessMethods PartitionAccessMethods, *PPartitionAccessMethods;

typedef struct SegmentDatabaseDescriptor SegmentDatabaseDescriptor, *PSegmentDatabaseDescriptor;

typedef uint32 bitmapword;

typedef struct RelFileNodeBackend RelFileNodeBackend, *PRelFileNodeBackend;

typedef struct _MdfdVec _MdfdVec, *P_MdfdVec;

typedef struct dlist_node dlist_node, *Pdlist_node;

typedef struct nameData nameData, *PnameData;

typedef struct nameData NameData;

typedef float float4;

typedef struct FormData_pg_attribute FormData_pg_attribute, *PFormData_pg_attribute;

typedef struct FormData_pg_attribute * Form_pg_attribute;

typedef struct tupleConstr tupleConstr, *PtupleConstr;

typedef struct tupleConstr TupleConstr;

typedef struct LockRelId LockRelId, *PLockRelId;

typedef struct RewriteRule RewriteRule, *PRewriteRule;

typedef struct Trigger Trigger, *PTrigger;

typedef enum GpPolicyType {
    POLICYTYPE_ENTRY=1,
    POLICYTYPE_PARTITIONED=0,
    POLICYTYPE_REPLICATED=2
} GpPolicyType;

typedef struct int2vector int2vector, *Pint2vector;

typedef struct Node * fmNodePtr;

typedef void (* GetForeignRelSize_function)(struct PlannerInfo *, struct RelOptInfo *, Oid);

typedef void (* GetForeignPaths_function)(struct PlannerInfo *, struct RelOptInfo *, Oid);

typedef struct Scan Scan, *PScan;

typedef struct PlannerGlobal PlannerGlobal, *PPlannerGlobal;

typedef struct Bitmapset * Relids;

typedef struct PlannerConfig PlannerConfig, *PPlannerConfig;

typedef enum RelOptKind {
    RELOPT_BASEREL=0,
    RELOPT_DEADREL=3,
    RELOPT_JOINREL=1,
    RELOPT_OTHER_MEMBER_REL=2
} RelOptKind;

typedef struct Path Path, *PPath;

typedef enum RTEKind {
    RTE_CTE=6,
    RTE_FUNCTION=3,
    RTE_JOIN=2,
    RTE_RELATION=0,
    RTE_SUBQUERY=1,
    RTE_TABLEFUNCTION=7,
    RTE_VALUES=4,
    RTE_VOID=5
} RTEKind;

typedef struct ExtTableEntry ExtTableEntry, *PExtTableEntry;

typedef struct QualCost QualCost, *PQualCost;

typedef struct ForeignTable ForeignTable, *PForeignTable;

typedef struct ScanState ScanState, *PScanState;

typedef void (* ReScanForeignScan_function)(struct ForeignScanState *);

typedef void (* EndForeignScan_function)(struct ForeignScanState *);

typedef enum QuerySource {
    QSRC_INSTEAD_RULE=2,
    QSRC_NON_INSTEAD_RULE=4,
    QSRC_ORIGINAL=0,
    QSRC_PARSER=1,
    QSRC_PLANNER=5,
    QSRC_QUAL_INSTEAD_RULE=3
} QuerySource;

typedef struct FromExpr FromExpr, *PFromExpr;

typedef uint8 ParentStmtType;

typedef enum JoinType {
    JOIN_ANTI=5,
    JOIN_DEDUP_SEMI=9,
    JOIN_DEDUP_SEMI_REVERSE=10,
    JOIN_FULL=2,
    JOIN_INNER=0,
    JOIN_LASJ_NOTIN=6,
    JOIN_LEFT=1,
    JOIN_RIGHT=3,
    JOIN_SEMI=4,
    JOIN_UNIQUE_INNER=8,
    JOIN_UNIQUE_OUTER=7
} JoinType;

typedef struct Alias Alias, *PAlias;

typedef uint32 AclMode;

typedef struct PlanState PlanState, *PPlanState;

typedef struct EPQState EPQState, *PEPQState;

typedef TupleTableSlot * (* ExecForeignInsert_function)(struct EState *, struct ResultRelInfo *, struct TupleTableSlot *, struct TupleTableSlot *);

typedef TupleTableSlot * (* ExecForeignUpdate_function)(struct EState *, struct ResultRelInfo *, struct TupleTableSlot *, struct TupleTableSlot *);

typedef TupleTableSlot * (* ExecForeignDelete_function)(struct EState *, struct ResultRelInfo *, struct TupleTableSlot *, struct TupleTableSlot *);

typedef struct StringInfoData * StringInfo;

typedef enum ExplainFormat {
    EXPLAIN_FORMAT_JSON=2,
    EXPLAIN_FORMAT_TEXT=0,
    EXPLAIN_FORMAT_XML=1,
    EXPLAIN_FORMAT_YAML=3
} ExplainFormat;

typedef struct ExplainStateExtra ExplainStateExtra, *PExplainStateExtra;

typedef struct PgStat_TableXactStatus PgStat_TableXactStatus, *PPgStat_TableXactStatus;

typedef struct PgStat_TableCounts PgStat_TableCounts, *PPgStat_TableCounts;

typedef struct BlockIdData BlockIdData, *PBlockIdData;

typedef uint16 OffsetNumber;

typedef union anon_union_for_t_choice anon_union_for_t_choice, *Panon_union_for_t_choice;

typedef uint8 bits8;

typedef struct DistributedSnapshot DistributedSnapshot, *PDistributedSnapshot;

typedef double Cost;

typedef struct Flow Flow, *PFlow;

typedef enum DispatchMethod {
    DISPATCH_PARALLEL=2,
    DISPATCH_SEQUENTIAL=1,
    DISPATCH_UNDETERMINED=0
} DispatchMethod;

typedef struct RangeVar RangeVar, *PRangeVar;

typedef enum OnCommitAction {
    ONCOMMIT_DELETE_ROWS=2,
    ONCOMMIT_DROP=3,
    ONCOMMIT_NOOP=0,
    ONCOMMIT_PRESERVE_ROWS=1
} OnCommitAction;

typedef struct BufferUsage BufferUsage, *PBufferUsage;

typedef struct CdbExplain_NodeSummary CdbExplain_NodeSummary, *PCdbExplain_NodeSummary;

typedef enum ExprDoneCond {
    ExprEndResult=2,
    ExprMultipleResult=1,
    ExprSingleResult=0
} ExprDoneCond;

typedef struct MemTupleBindingCols MemTupleBindingCols, *PMemTupleBindingCols;

typedef int File;

typedef struct FileSegInfo FileSegInfo, *PFileSegInfo;

typedef struct VarBlockMaker VarBlockMaker, *PVarBlockMaker;

typedef struct AppendOnlyStorageAttributes AppendOnlyStorageAttributes, *PAppendOnlyStorageAttributes;

typedef struct AppendOnlyStorageWrite AppendOnlyStorageWrite, *PAppendOnlyStorageWrite;

typedef struct AppendOnlyBlockDirectory AppendOnlyBlockDirectory, *PAppendOnlyBlockDirectory;

typedef struct AOCSFileSegInfo AOCSFileSegInfo, *PAOCSFileSegInfo;

typedef struct DatumStreamWrite DatumStreamWrite, *PDatumStreamWrite;

typedef struct URL_FILE URL_FILE, *PURL_FILE;

typedef struct FormatterData FormatterData, *PFormatterData;

typedef struct CopyStateData CopyStateData, *PCopyStateData;

typedef struct BufferAccessStrategyData BufferAccessStrategyData, *PBufferAccessStrategyData;

typedef struct BufferAccessStrategyData * BufferAccessStrategy;

typedef enum LockClauseStrength {
    LCS_FORKEYSHARE=0,
    LCS_FORNOKEYUPDATE=2,
    LCS_FORSHARE=1,
    LCS_FORUPDATE=3
} LockClauseStrength;

typedef struct CdbDispatchResult CdbDispatchResult, *PCdbDispatchResult;

typedef struct CdbDispatchResults_SliceInfo CdbDispatchResults_SliceInfo, *PCdbDispatchResults_SliceInfo;

typedef long __time_t;

typedef long __suseconds_t;

typedef struct CdbExplain_SliceWorker CdbExplain_SliceWorker, *PCdbExplain_SliceWorker;

typedef uint64 MemoryAccountIdType;

typedef struct CdbExplain_Agg CdbExplain_Agg, *PCdbExplain_Agg;

typedef struct CdbExplain_DispatchSummary CdbExplain_DispatchSummary, *PCdbExplain_DispatchSummary;

typedef struct CdbComponentDatabaseInfo CdbComponentDatabaseInfo, *PCdbComponentDatabaseInfo;

typedef struct pg_conn pg_conn, *Ppg_conn;

typedef struct pg_conn PGconn;

typedef struct attrDefault attrDefault, *PattrDefault;

typedef struct attrDefault AttrDefault;

typedef struct constrCheck constrCheck, *PconstrCheck;

typedef struct constrCheck ConstrCheck;

typedef struct ApplyShareInputContext ApplyShareInputContext, *PApplyShareInputContext;

typedef struct ParamPathInfo ParamPathInfo, *PParamPathInfo;

typedef double EstimatedBytes;

typedef struct CdbPathLocus CdbPathLocus, *PCdbPathLocus;

typedef struct gpmon_packet_t gpmon_packet_t, *Pgpmon_packet_t;

typedef int64 PgStat_Counter;

typedef struct HeapTupleFields HeapTupleFields, *PHeapTupleFields;

typedef struct DatumTupleFields DatumTupleFields, *PDatumTupleFields;

typedef uint32 DistributedTransactionTimeStamp;

typedef uint32 DistributedTransactionId;

typedef int32 DistributedSnapshotId;

typedef enum FlowType {
    FLOW_PARTITIONED=3,
    FLOW_REPLICATED=2,
    FLOW_SINGLETON=1,
    FLOW_UNDEFINED=0
} FlowType;

typedef enum Movement {
    MOVEMENT_BROADCAST=2,
    MOVEMENT_EXPLICIT=5,
    MOVEMENT_FOCUS=1,
    MOVEMENT_LIM_RESTRUCT=4,
    MOVEMENT_NONE=0,
    MOVEMENT_REPARTITION=3
} Movement;

typedef enum CdbLocusType {
    CdbLocusType_End=9,
    CdbLocusType_Entry=1,
    CdbLocusType_General=3,
    CdbLocusType_Hashed=6,
    CdbLocusType_HashedOJ=7,
    CdbLocusType_Null=0,
    CdbLocusType_Replicated=5,
    CdbLocusType_SegmentGeneral=4,
    CdbLocusType_SingleQE=2,
    CdbLocusType_Strewn=8
} CdbLocusType;

typedef enum InhOption {
    INH_DEFAULT=2,
    INH_NO=0,
    INH_YES=1
} InhOption;

typedef struct CdbExplain_StatInst CdbExplain_StatInst, *PCdbExplain_StatInst;

typedef struct MemTupleAttrBinding MemTupleAttrBinding, *PMemTupleAttrBinding;

typedef struct TupleVisibilitySummary TupleVisibilitySummary, *PTupleVisibilitySummary;

typedef enum FileSegInfoState {
    AOSEG_STATE_AWAITING_DROP=2,
    AOSEG_STATE_DEFAULT=1,
    AOSEG_STATE_USECURRENT=0
} FileSegInfoState;

typedef struct VarBlockHeader VarBlockHeader, *PVarBlockHeader;

typedef int32 VarBlockByteLen;

typedef enum AORelationVersion {
    AORelationVersion_Aligned64bit=2,
    AORelationVersion_None=0,
    AORelationVersion_Original=1,
    AORelationVersion_PG83=3,
    MaxAORelationVersion=4
} AORelationVersion;

typedef struct BufferedAppend BufferedAppend, *PBufferedAppend;

typedef enum AoHeaderKind {
    AoHeaderKind_BulkDenseContent=4,
    AoHeaderKind_LargeContent=2,
    AoHeaderKind_NonBulkDenseContent=3,
    AoHeaderKind_None=0,
    AoHeaderKind_SmallContent=1,
    MaxAoHeaderKind=5
} AoHeaderKind;

typedef struct CompressionState CompressionState, *PCompressionState;

typedef struct MinipagePerColumnGroup MinipagePerColumnGroup, *PMinipagePerColumnGroup;

typedef struct ScanKeyData ScanKeyData, *PScanKeyData;

typedef struct ScanKeyData * ScanKey;

typedef uint16 StrategyNumber;

typedef struct AOCSVPInfo AOCSVPInfo, *PAOCSVPInfo;

typedef struct DatumStreamTypeInfo DatumStreamTypeInfo, *PDatumStreamTypeInfo;

typedef enum DatumStreamVersion {
    DatumStreamVersion_Dense=1,
    DatumStreamVersion_Dense_Enhanced=2,
    DatumStreamVersion_Original=0,
    MaxDatumStreamVersion=3
} DatumStreamVersion;

typedef struct DatumStreamBlockWrite DatumStreamBlockWrite, *PDatumStreamBlockWrite;

typedef enum fcurl_type_e {
    CFTYPE_CURL=2,
    CFTYPE_CUSTOM=4,
    CFTYPE_EXEC=3,
    CFTYPE_FILE=1,
    CFTYPE_NONE=0
} fcurl_type_e;

typedef enum FmtNotification {
    FMT_NEED_MORE_DATA=1,
    FMT_NONE=0
} FmtNotification;

typedef enum CopyDest {
    COPY_CALLBACK=3,
    COPY_FILE=0,
    COPY_NEW_FE=2,
    COPY_OLD_FE=1
} CopyDest;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef struct _IO_FILE FILE;

typedef enum EolType {
    EOL_CR=2,
    EOL_CRNL=3,
    EOL_NL=1,
    EOL_UNKNOWN=0
} EolType;

typedef struct QueryDesc QueryDesc, *PQueryDesc;

typedef struct SingleRowErrorDesc SingleRowErrorDesc, *PSingleRowErrorDesc;

typedef enum CopyDispatchMode {
    COPY_DIRECT=0,
    COPY_DISPATCH=1,
    COPY_EXECUTOR=2
} CopyDispatchMode;

typedef struct ExprState ExprState, *PExprState;

typedef enum CopyErrMode {
    ALL_OR_NOTHING=0,
    SREH_IGNORE=1,
    SREH_LOG=2
} CopyErrMode;

typedef struct CdbSreh CdbSreh, *PCdbSreh;

typedef struct ProgramPipes ProgramPipes, *PProgramPipes;

typedef struct CdbCopy CdbCopy, *PCdbCopy;

typedef struct PQExpBufferData PQExpBufferData, *PPQExpBufferData;

typedef enum DispatchWaitMode {
    DISPATCH_WAIT_CANCEL=2,
    DISPATCH_WAIT_FINISH=1,
    DISPATCH_WAIT_NONE=0
} DispatchWaitMode;

typedef struct GpSegConfigEntry GpSegConfigEntry, *PGpSegConfigEntry;

typedef struct CdbComponentDatabases CdbComponentDatabases, *PCdbComponentDatabases;

typedef struct PGNoticeHooks PGNoticeHooks, *PPGNoticeHooks;

typedef struct pg_result pg_result, *Ppg_result;

typedef struct pg_result PGresult;

typedef struct PGEvent PGEvent, *PPGEvent;

typedef enum PGEventId {
    PGEVT_CONNDESTROY=2,
    PGEVT_CONNRESET=1,
    PGEVT_REGISTER=0,
    PGEVT_RESULTCOPY=4,
    PGEVT_RESULTCREATE=3,
    PGEVT_RESULTDESTROY=5
} PGEventId;

typedef enum ConnStatusType {
    CONNECTION_AUTH_OK=5,
    CONNECTION_AWAITING_RESPONSE=4,
    CONNECTION_BAD=1,
    CONNECTION_MADE=3,
    CONNECTION_NEEDED=8,
    CONNECTION_OK=0,
    CONNECTION_SETENV=6,
    CONNECTION_SSL_STARTUP=7,
    CONNECTION_STARTED=2
} ConnStatusType;

typedef enum PGAsyncStatusType {
    PGASYNC_BUSY=1,
    PGASYNC_COPY_BOTH=5,
    PGASYNC_COPY_IN=3,
    PGASYNC_COPY_OUT=4,
    PGASYNC_IDLE=0,
    PGASYNC_READY=2
} PGAsyncStatusType;

typedef enum PGTransactionStatusType {
    PQTRANS_ACTIVE=1,
    PQTRANS_IDLE=0,
    PQTRANS_INERROR=3,
    PQTRANS_INTRANS=2,
    PQTRANS_UNKNOWN=4
} PGTransactionStatusType;

typedef enum PGQueryClass {
    PGQUERY_DESCRIBE=3,
    PGQUERY_EXTENDED=1,
    PGQUERY_PREPARE=2,
    PGQUERY_SIMPLE=0
} PGQueryClass;

typedef struct pgNotify pgNotify, *PpgNotify;

typedef struct pgNotify PGnotify;

typedef int pgsocket;

typedef struct SockAddr SockAddr, *PSockAddr;

typedef uint32 ProtocolVersion;

typedef struct addrinfo addrinfo, *Paddrinfo;

typedef enum PGSetenvStatusType {
    SETENV_STATE_CLIENT_ENCODING_SEND=0,
    SETENV_STATE_CLIENT_ENCODING_WAIT=1,
    SETENV_STATE_IDLE=8,
    SETENV_STATE_OPTION_SEND=2,
    SETENV_STATE_OPTION_WAIT=3,
    SETENV_STATE_QUERY1_SEND=4,
    SETENV_STATE_QUERY1_WAIT=5,
    SETENV_STATE_QUERY2_SEND=6,
    SETENV_STATE_QUERY2_WAIT=7
} PGSetenvStatusType;

typedef struct PQEnvironmentOption PQEnvironmentOption, *PPQEnvironmentOption;

typedef struct pgParameterStatus pgParameterStatus, *PpgParameterStatus;

typedef enum PGVerbosity {
    PQERRORS_DEFAULT=1,
    PQERRORS_TERSE=0,
    PQERRORS_VERBOSE=2
} PGVerbosity;

typedef struct pgLobjfuncs pgLobjfuncs, *PpgLobjfuncs;

typedef struct pgLobjfuncs PGlobjfuncs;

typedef struct pgDataValue pgDataValue, *PpgDataValue;

typedef struct pgDataValue PGdataValue;

typedef struct ShareInputScan ShareInputScan, *PShareInputScan;

typedef union anon_union_for_u anon_union_for_u, *Panon_union_for_u;

typedef union anon_union_for_t_field3 anon_union_for_t_field3, *Panon_union_for_t_field3;

typedef enum ExplainSortMethod {
    EXTERNAL_MERGE=4,
    EXTERNAL_SORT=3,
    IN_PROGRESS_SORT=5,
    QUICK_SORT=2,
    TOP_N_HEAP_SORT=1,
    UNINITIALIZED_SORT=0
} ExplainSortMethod;

typedef enum ExplainSortSpaceType {
    DISK_SORT_SPACE_TYPE=2,
    MEMORY_SORT_SPACE_TYPE=1,
    UNINITIALIZED_SORT_SPACE_TYPE=0
} ExplainSortSpaceType;

typedef enum MemTupleBindFlag {
    MTB_ByRef=3,
    MTB_ByRef_CStr=4,
    MTB_ByVal_Native=1,
    MTB_ByVal_Ptr=2
} MemTupleBindFlag;

typedef enum TupleTransactionStatus {
    TupleTransactionStatus_CLogAborted=6,
    TupleTransactionStatus_CLogCommitted=5,
    TupleTransactionStatus_CLogInProgress=4,
    TupleTransactionStatus_CLogSubCommitted=7,
    TupleTransactionStatus_Frozen=1,
    TupleTransactionStatus_HintAborted=3,
    TupleTransactionStatus_HintCommitted=2,
    TupleTransactionStatus_None=0
} TupleTransactionStatus;

typedef enum TupleVisibilityStatus {
    TupleVisibilityStatus_Aborted=2,
    TupleVisibilityStatus_InProgress=1,
    TupleVisibilityStatus_Now=4,
    TupleVisibilityStatus_Past=3,
    TupleVisibilityStatus_Unknown=0
} TupleVisibilityStatus;

typedef struct Minipage Minipage, *PMinipage;

typedef struct AOCSVPInfoEntry AOCSVPInfoEntry, *PAOCSVPInfoEntry;

typedef struct DatumStreamBitMapWrite DatumStreamBitMapWrite, *PDatumStreamBitMapWrite;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef long __off_t;

typedef void _IO_lock_t;

typedef long __off64_t;

typedef struct _DestReceiver _DestReceiver, *P_DestReceiver;

typedef struct _DestReceiver DestReceiver;

typedef struct QueryDispatchDesc QueryDispatchDesc, *PQueryDispatchDesc;

typedef struct pgresAttDesc pgresAttDesc, *PpgresAttDesc;

typedef struct pgresAttDesc PGresAttDesc;

typedef struct pgresAttValue pgresAttValue, *PpgresAttValue;

typedef struct pgresAttValue PGresAttValue;

typedef struct pgresParamDesc pgresParamDesc, *PpgresParamDesc;

typedef struct pgresParamDesc PGresParamDesc;

typedef enum ExecStatusType {
    PGRES_BAD_RESPONSE=5,
    PGRES_COMMAND_OK=1,
    PGRES_COPY_BOTH=8,
    PGRES_COPY_IN=4,
    PGRES_COPY_OUT=3,
    PGRES_EMPTY_QUERY=0,
    PGRES_FATAL_ERROR=7,
    PGRES_NONFATAL_ERROR=6,
    PGRES_SINGLE_TUPLE=9,
    PGRES_TUPLES_OK=2
} ExecStatusType;

typedef struct pgMessageField pgMessageField, *PpgMessageField;

typedef struct pgMessageField PGMessageField;

typedef union pgresult_data pgresult_data, *Ppgresult_data;

typedef union pgresult_data PGresult_data;

typedef struct pgCdbStatCell pgCdbStatCell, *PpgCdbStatCell;

typedef struct PQaoRelTupCount PQaoRelTupCount, *PPQaoRelTupCount;

typedef struct sockaddr sockaddr, *Psockaddr;

typedef enum ShareType {
    SHARE_MATERIAL=1,
    SHARE_MATERIAL_XSLICE=2,
    SHARE_NOTSHARED=0,
    SHARE_SORT=3,
    SHARE_SORT_XSLICE=4
} ShareType;

typedef struct gpmon_hello_t gpmon_hello_t, *Pgpmon_hello_t;

typedef struct gpmon_metrics_t gpmon_metrics_t, *Pgpmon_metrics_t;

typedef struct gpmon_qlog_t gpmon_qlog_t, *Pgpmon_qlog_t;

typedef struct gpmon_qexec_t gpmon_qexec_t, *Pgpmon_qexec_t;

typedef struct gpmon_seginfo_t gpmon_seginfo_t, *Pgpmon_seginfo_t;

typedef struct gpmon_fsinfo_t gpmon_fsinfo_t, *Pgpmon_fsinfo_t;

typedef struct MinipageEntry MinipageEntry, *PMinipageEntry;

typedef enum CommandDest {
    DestCopyOut=7,
    DestDebug=1,
    DestIntoRel=6,
    DestNone=0,
    DestRemote=2,
    DestRemoteExecute=3,
    DestSPI=4,
    DestSQLFunction=8,
    DestTransientRel=9,
    DestTuplestore=5
} CommandDest;

//typedef struct anon_struct_for_mem anon_struct_for_mem, *Panon_struct_for_mem;

typedef struct anon_struct_for_swap anon_struct_for_swap, *Panon_struct_for_swap;

typedef struct anon_struct_for_cpu anon_struct_for_cpu, *Panon_struct_for_cpu;

typedef struct anon_struct_for_load_avg anon_struct_for_load_avg, *Panon_struct_for_load_avg;

typedef struct anon_struct_for_disk anon_struct_for_disk, *Panon_struct_for_disk;

typedef struct anon_struct_for_net anon_struct_for_net, *Panon_struct_for_net;

typedef struct gpmon_qlogkey_t gpmon_qlogkey_t, *Pgpmon_qlogkey_t;

typedef struct gpmon_proc_metrics_t gpmon_proc_metrics_t, *Pgpmon_proc_metrics_t;

typedef struct gpmon_qexeckey_t gpmon_qexeckey_t, *Pgpmon_qexeckey_t;

typedef struct gpmon_fsinfokey_t gpmon_fsinfokey_t, *Pgpmon_fsinfokey_t;


/* WARNING! conflicting data type names: /DWARF/_UNCATEGORIZED_/gpmon_proc_metrics_t/anon_struct_for_mem - /DWARF/_UNCATEGORIZED_/gpmon_metrics_t/anon_struct_for_mem */

struct anon_struct_for_mem { /* DWARF DIE: d66c */
    uint64 total;
    uint64 used;
    uint64 actual_used;
    uint64 actual_free;
};


typedef struct gpmon_qexec_hash_key_t gpmon_qexec_hash_key_t, *Pgpmon_qexec_hash_key_t;

struct ExprContext_CB { /* DWARF DIE: d9c9 */
    struct ExprContext_CB * next;
    void (* function)(Datum);
    Datum arg;
};

struct Query { /* DWARF DIE: c434 */
    enum NodeTag type;
    enum CmdType commandType;
    enum QuerySource querySource;
    uint32 queryId;
    bool canSetTag;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    struct Node * utilityStmt;
    int resultRelation;
    bool hasAggs;
    bool hasWindowFuncs;
    bool hasSubLinks;
    bool hasDynamicFunctions;
    bool hasFuncsWithExecRestrictions;
    bool hasDistinctOn;
    bool hasRecursive;
    bool hasModifyingCTE;
    bool hasForUpdate;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    struct List * cteList;
    struct List * rtable;
    struct FromExpr * jointree;
    struct List * targetList;
    struct List * withCheckOptions;
    struct List * returningList;
    struct List * groupClause;
    struct Node * havingQual;
    struct List * windowClause;
    struct List * distinctClause;
    struct List * sortClause;
    struct List * scatterClause;
    bool isTableValueSelect;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    struct Node * limitOffset;
    struct Node * limitCount;
    struct List * rowMarks;
    struct Node * setOperations;
    struct List * constraintDeps;
    struct GpPolicy * intoPolicy;
    ParentStmtType parentStmtType;
    undefined field_0xc9;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
};

struct Node { /* DWARF DIE: 1d91 */
    enum NodeTag type;
};

struct gpmon_qlogkey_t { /* DWARF DIE: d3db */
    int32 tmid;
    int32 ssid;
    int32 ccnt;
};

struct gpmon_proc_metrics_t { /* DWARF DIE: d7ad */
    uint32 fd_cnt;
    float cpu_pct;
    struct anon_struct_for_mem mem;
};

struct gpmon_qlog_t { /* DWARF DIE: d417 */
    struct gpmon_qlogkey_t key;
    char user[64];
    char db[64];
    int32 tsubmit;
    int32 tstart;
    int32 tfin;
    int32 status;
    int32 cost;
    int64 cpu_elapsed;
    struct gpmon_proc_metrics_t p_metrics;
};

struct gpmon_qexec_hash_key_t { /* DWARF DIE: d80b */
    int16 segid;
    undefined field_0x2;
    undefined field_0x3;
    int32 pid;
    int16 nid;
    undefined field_0xa;
    undefined field_0xb;
};

struct gpmon_qexeckey_t { /* DWARF DIE: d847 */
    int32 tmid;
    int32 ssid;
    int16 ccnt;
    undefined field_0xa;
    undefined field_0xb;
    struct gpmon_qexec_hash_key_t hash_key;
};

struct gpmon_qexec_t { /* DWARF DIE: d4a6 */
    struct gpmon_qexeckey_t key;
    char _hname[64];
    uint8 status;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    uint64 _cpu_elapsed;
    struct gpmon_proc_metrics_t _p_metrics;
    uint64 rowsout;
};

struct gpmon_seginfo_t { /* DWARF DIE: d5a2 */
    int32 dbid;
    char hostname[64];
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    uint64 dynamic_memory_used;
    uint64 dynamic_memory_available;
};

struct gpmon_hello_t { /* DWARF DIE: d506 */
    int64 signature;
    int32 pid;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct anon_struct_for_disk { /* DWARF DIE: d730 */
    uint64 ro_rate;
    uint64 wo_rate;
    uint64 rb_rate;
    uint64 wb_rate;
};

struct anon_struct_for_load_avg { /* DWARF DIE: d70b */
    float value[3];
};

struct anon_struct_for_cpu { /* DWARF DIE: d6de */
    float user_pct;
    float sys_pct;
    float idle_pct;
};

struct anon_struct_for_swap { /* DWARF DIE: d6a5 */
    uint64 total;
    uint64 used;
    uint64 page_in;
    uint64 page_out;
};

struct anon_struct_for_net { /* DWARF DIE: d769 */
    uint64 rp_rate;
    uint64 wp_rate;
    uint64 rb_rate;
    uint64 wb_rate;
};

struct gpmon_metrics_t { /* DWARF DIE: d536 */
    char hname[64];
    struct anon_struct_for_mem mem;
    struct anon_struct_for_swap swap;
    struct anon_struct_for_cpu cpu;
    struct anon_struct_for_load_avg load_avg;
    struct anon_struct_for_disk disk;
    struct anon_struct_for_net net;
};

struct gpmon_fsinfokey_t { /* DWARF DIE: d5ea */
    char fsname[255];
    char hostname[64];
};

struct gpmon_fsinfo_t { /* DWARF DIE: d61b */
    struct gpmon_fsinfokey_t key;
    undefined field_0x13f;
    int64 bytes_used;
    int64 bytes_available;
    int64 bytes_total;
};

union anon_union_for_u { /* DWARF DIE: d88f */
    struct gpmon_hello_t hello;
    struct gpmon_metrics_t metrics;
    struct gpmon_qlog_t qlog;
    struct gpmon_qexec_t qexec;
    struct gpmon_seginfo_t seginfo;
    struct gpmon_fsinfo_t fsinfo;
};

struct gpmon_packet_t { /* DWARF DIE: d390 */
    int32 magic;
    int16 version;
    int16 pkttype;
    union anon_union_for_u u;
};

struct PlanState { /* DWARF DIE: e34e */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct Plan * plan;
    struct EState * state;
    bool fHadSentGpmon;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct List * targetlist;
    struct List * qual;
    struct PlanState * lefttree;
    struct PlanState * righttree;
    struct List * initPlan;
    struct List * subPlan;
    struct Bitmapset * chgParam;
    struct TupleTableSlot * ps_ResultTupleSlot;
    struct ExprContext * ps_ExprContext;
    struct ProjectionInfo * ps_ProjInfo;
    struct Instrumentation * instrument;
    struct StringInfoData * cdbexplainbuf;
    void (* cdbexplainfun)(struct PlanState *, struct StringInfoData *);
    int gpmon_plan_tick;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    struct gpmon_packet_t gpmon_pkt;
    bool fHadSentNodeStart;
    bool squelched;
    undefined field_0x1f2;
    undefined field_0x1f3;
    undefined field_0x1f4;
    undefined field_0x1f5;
    undefined field_0x1f6;
    undefined field_0x1f7;
    MemoryAccountIdType memoryAccountId;
};

struct ScanState { /* DWARF DIE: 30c343 */
    struct PlanState ps;
    Relation ss_currentRelation;
    struct TupleTableSlot * ss_ScanTupleSlot;
};

struct ParseState { /* DWARF DIE: bcb2 */
    struct ParseState * parentParseState;
    char * p_sourcetext;
    struct List * p_rtable;
    struct List * p_joinexprs;
    struct List * p_joinlist;
    struct List * p_namespace;
    bool p_lateral_active;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    struct List * p_ctenamespace;
    struct List * p_future_ctes;
    struct CommonTableExpr * p_parent_cte;
    struct List * p_windowdefs;
    enum ParseExprKind p_expr_kind;
    int p_next_resno;
    struct List * p_locking_clause;
    struct Node * p_value_substitute;
    bool p_hasAggs;
    bool p_hasWindowFuncs;
    bool p_hasSubLinks;
    bool p_hasModifyingCTE;
    bool p_is_insert;
    bool p_is_update;
    undefined field_0x76;
    undefined field_0x77;
    struct LockingClause * p_lockclause_from_parent;
    Relation p_target_relation;
    struct RangeTblEntry * p_target_rangetblentry;
    struct HTAB * p_namecache;
    bool p_hasTblValueExpr;
    bool p_hasDynamicFunction;
    bool p_hasFuncsWithExecRestrictions;
    undefined field_0x9b;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    struct List * p_grp_tles;
    Node * (* p_pre_columnref_hook)(struct ParseState *, struct ColumnRef *);
    Node * (* p_post_columnref_hook)(struct ParseState *, struct ColumnRef *, struct Node *);
    Node * (* p_paramref_hook)(struct ParseState *, struct ParamRef *);
    Node * (* p_coerce_param_hook)(struct ParseState *, struct Param *, Oid, int32, int);
    void * p_ref_hook_state;
};

struct HTAB { /* DWARF DIE: 256b */
};

struct Gang { /* DWARF DIE: 1a65ba */
    enum GangType type;
    int gang_id;
    int size;
    bool dispatcherActive;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct SegmentDatabaseDescriptor * * db_descriptors;
    bool allocated;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
};

struct BlockIdData { /* DWARF DIE: cb9 */
    uint16 bi_hi;
    uint16 bi_lo;
};

struct DirectDispatchInfo { /* DWARF DIE: caee */
    bool isDirectDispatch;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * contentIds;
};

struct Plan { /* DWARF DIE: c919 */
    enum NodeTag type;
    int plan_node_id;
    Cost startup_cost;
    Cost total_cost;
    double plan_rows;
    int plan_width;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    struct List * targetlist;
    struct List * qual;
    struct Plan * lefttree;
    struct Plan * righttree;
    struct List * initPlan;
    struct Bitmapset * extParam;
    struct Bitmapset * allParam;
    struct Flow * flow;
    enum DispatchMethod dispatch;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    struct DirectDispatchInfo directDispatch;
    int nMotionNodes;
    int nInitPlans;
    struct Node * sliceTable;
    uint64 operatorMemKB;
    struct Plan * motionNode;
};

struct Scan { /* DWARF DIE: b2ec3 */
    struct Plan plan;
    Index scanrelid;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
};

struct ShareInputScan { /* DWARF DIE: b2f3a */
    struct Scan scan;
    enum ShareType share_type;
    int share_id;
    int driver_slice;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
};

struct PgStat_TableCounts { /* DWARF DIE: 558a4 */
    PgStat_Counter t_numscans;
    PgStat_Counter t_tuples_returned;
    PgStat_Counter t_tuples_fetched;
    PgStat_Counter t_tuples_inserted;
    PgStat_Counter t_tuples_updated;
    PgStat_Counter t_tuples_deleted;
    PgStat_Counter t_tuples_hot_updated;
    PgStat_Counter t_delta_live_tuples;
    PgStat_Counter t_delta_dead_tuples;
    PgStat_Counter t_changed_tuples;
    PgStat_Counter t_blocks_fetched;
    PgStat_Counter t_blocks_hit;
};

struct PgStat_TableStatus { /* DWARF DIE: 54129 */
    Oid t_id;
    bool t_shared;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct PgStat_TableXactStatus * trans;
    struct PgStat_TableCounts t_counts;
};

struct PGNoticeHooks { /* DWARF DIE: 4d7bfe */
    void (* noticeRec)(void *, PGresult *);
    void * noticeRecArg;
    void (* noticeProc)(void *, char *);
    void * noticeProcArg;
};

struct pg_result { /* DWARF DIE: 4d7750 */
    int ntups;
    int numAttributes;
    PGresAttDesc * attDescs;
    PGresAttValue * * tuples;
    int tupArrSize;
    int numParameters;
    PGresParamDesc * paramDescs;
    enum ExecStatusType resultStatus;
    char cmdStatus[72];
    int binary;
    struct PGNoticeHooks noticeHooks;
    struct PGEvent * events;
    int nEvents;
    int client_encoding;
    char * errMsg;
    PGMessageField * errFields;
    char null_field[1];
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    PGresult_data * curBlock;
    int curOffset;
    int spaceLeft;
    struct pgCdbStatCell * cdbstats;
    void * extras;
    int extraslen;
    int numRejected;
    int64 numCompleted;
    int naotupcounts;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    struct PQaoRelTupCount * aotupcounts;
};

struct CompressionState { /* DWARF DIE: 1140e1 */
    size_t (* desired_sz)(size_t);
    void * opaque;
};

struct FmgrInfo { /* DWARF DIE: 265d */
    Datum (* fn_addr)(FunctionCallInfo);
    Oid fn_oid;
    short fn_nargs;
    bool fn_strict;
    bool fn_retset;
    uchar fn_stats;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    void * fn_extra;
    MemoryContext fn_mcxt;
    fmNodePtr fn_expr;
};

struct RangeVar { /* DWARF DIE: bf9c */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * catalogname;
    char * schemaname;
    char * relname;
    enum InhOption inhOpt;
    char relpersistence;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    struct Alias * alias;
    int location;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
};

struct ForeignScanState { /* DWARF DIE: 49bee2 */
    struct ScanState ss;
    struct FdwRoutine * fdwroutine;
    void * fdw_state;
};

struct PQaoRelTupCount { /* DWARF DIE: 4d79aa */
    Oid aorelid;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    long tupcount;
};

struct RelFileNode { /* DWARF DIE: eb4 */
    Oid spcNode;
    Oid dbNode;
    Oid relNode;
};

struct Expr { /* DWARF DIE: c104 */
    enum NodeTag type;
};

struct pgParameterStatus { /* DWARF DIE: 4d7e13 */
    struct pgParameterStatus * next;
    char * name;
    char * value;
};

struct VarBlockHeader { /* DWARF DIE: 113ff7 */
    uint32 bytes_0_3;
    uint32 bytes_4_7;
};

struct AppendOnlyStorageAttributes { /* DWARF DIE: 114081 */
    bool compress;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * compressType;
    int compressLevel;
    int overflowSize;
    bool checksum;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    int safeFSWriteSize;
};

struct PQEnvironmentOption { /* DWARF DIE: 4d7dda */
    char * envName;
    char * pgName;
};

struct DatumStreamBitMapWrite { /* DWARF DIE: 2bc556 */
    uint8 * buffer;
    int32 bufferSize;
    uint8 byteBit;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    uint8 * bytePointer;
    int32 bitOnCount;
    int32 bitCount;
};

struct TupleRemapper { /* DWARF DIE: 5983fe */
};

struct ForeignScan { /* DWARF DIE: 499acd */
    struct Scan scan;
    struct List * fdw_exprs;
    struct List * fdw_private;
    bool fsSystemCol;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
};

struct pgCdbStatCell { /* DWARF DIE: 4d7c96 */
    struct pgCdbStatCell * next;
    int len;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    char * data;
};

struct MemTupleBindingCols { /* DWARF DIE: 2b06 */
    uint32 var_start;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct MemTupleAttrBinding * bindings;
    short * null_saves;
    short * null_saves_aligned;
    bool has_null_saves_alignment_mismatch;
    bool has_dropped_attr_alignment_mismatch;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
};

struct MemTupleBinding { /* DWARF DIE: 2b72 */
    TupleDesc tupdesc;
    int column_align;
    int null_bitmap_extra_size;
    struct MemTupleBindingCols bind;
    struct MemTupleBindingCols large_bind;
};

struct ICBufferLink { /* DWARF DIE: 5987d9 */
    struct ICBufferLink * next;
    struct ICBufferLink * prev;
};

struct ICBufferList { /* DWARF DIE: 598833 */
    int length;
    enum ICBufferListType type;
    struct ICBufferLink head;
};

struct timeval { /* DWARF DIE: 7d71 */
    __time_t tv_sec;
    __suseconds_t tv_usec;
};

struct BufferUsage { /* DWARF DIE: ce00 */
    long shared_blks_hit;
    long shared_blks_read;
    long shared_blks_dirtied;
    long shared_blks_written;
    long local_blks_hit;
    long local_blks_read;
    long local_blks_dirtied;
    long local_blks_written;
    long temp_blks_read;
    long temp_blks_written;
    instr_time blk_read_time;
    instr_time blk_write_time;
};

struct Instrumentation { /* DWARF DIE: abb4 */
    bool need_timer;
    bool need_cdb;
    bool need_bufusage;
    bool running;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    instr_time starttime;
    instr_time counter;
    double firsttuple;
    uint64 tuplecount;
    struct BufferUsage bufusage_start;
    double startup;
    double total;
    uint64 ntuples;
    uint64 nloops;
    double nfiltered1;
    double nfiltered2;
    struct BufferUsage bufusage;
    double execmemused;
    double workmemused;
    double workmemwanted;
    instr_time firststart;
    bool workfileCreated;
    undefined field_0x171;
    undefined field_0x172;
    undefined field_0x173;
    int numPartScanned;
    char * sortMethod;
    char * sortSpaceType;
    long sortSpaceUsed;
    struct CdbExplain_NodeSummary * cdbNodeSummary;
};

struct LockRelId { /* DWARF DIE: b855 */
    Oid relId;
    Oid dbId;
};

struct constrCheck { /* DWARF DIE: 1ddc */
    char * ccname;
    char * ccbin;
    bool ccvalid;
    bool ccnoinherit;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct AppendOnlyBlockDirectory { /* DWARF DIE: 114733 */
    Relation aoRel;
    Snapshot appendOnlyMetaDataSnapshot;
    Relation blkdirRel;
    Relation blkdirIdx;
    int numColumnGroups;
    bool isAOCol;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    bool * proj;
    MemoryContext memoryContext;
    int totalSegfiles;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    struct FileSegInfo * * segmentFileInfo;
    int currentSegmentFileNum;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    struct FileSegInfo * currentSegmentFileInfo;
    struct MinipagePerColumnGroup * minipages;
    Datum * values;
    bool * nulls;
    int numScanKeys;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    ScanKey scanKeys;
    StrategyNumber * strategyNumbers;
};

struct RelFileNodeBackend { /* DWARF DIE: ef0 */
    struct RelFileNode node;
    BackendId backend;
};

struct BufferedAppend { /* DWARF DIE: 267f2c */
    char * relationName;
    int32 maxBufferLen;
    int32 maxLargeWriteLen;
    uint8 * memory;
    int32 memoryLen;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint8 * largeWriteMemory;
    uint8 * afterBufferMemory;
    int64 largeWritePosition;
    int32 largeWriteLen;
    int32 bufferLen;
    File file;
    struct RelFileNodeBackend relFileNode;
    int32 segmentFileNum;
    char * filePathName;
    int64 fileLen;
    int64 fileLen_uncompressed;
};

struct AppendOnlyStorageWrite { /* DWARF DIE: 268554 */
    bool isActive;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    MemoryContext memoryContext;
    int32 maxBufferLen;
    int32 largeWriteLen;
    enum AORelationVersion formatVersion;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    char * relationName;
    char * title;
    struct AppendOnlyStorageAttributes storageAttributes;
    int32 regularHeaderLen;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    struct BufferedAppend bufferedAppend;
    char * segmentFileName;
    File file;
    undefined field_0xd4;
    undefined field_0xd5;
    undefined field_0xd6;
    undefined field_0xd7;
    int64 startEof;
    struct RelFileNodeBackend relFileNode;
    int32 segmentFileNum;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    int64 bufferCount;
    bool isFirstRowNumSet;
    undefined field_0x101;
    undefined field_0x102;
    undefined field_0x103;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    int64 firstRowNum;
    int64 logicalBlockStartOffset;
    enum AoHeaderKind getBufferAoHeaderKind;
    int32 currentCompleteHeaderLen;
    uint8 * currentBuffer;
    uint8 * uncompressedBuffer;
    int32 compressionOverrunLen;
    int32 maxBufferWithCompressionOverrrunLen;
    uint8 * verifyWriteBuffer;
    struct CompressionState * compressionState;
    struct CompressionState * verifyWriteCompressionState;
    int blocksize;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    Datum (** compression_functions)(FunctionCallInfo);
    bool needsWAL;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
};

struct VarBlockMaker { /* DWARF DIE: 268128 */
    struct VarBlockHeader * header;
    VarBlockByteLen maxBufferLen;
    VarBlockByteLen currentItemLenSum;
    uint8 * tempScratchSpace;
    int tempScratchSpaceLen;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    uint8 * nextItemPtr;
    uint8 * last2ByteOffsetPtr;
    int currentItemCount;
    int maxItemCount;
};

struct AppendOnlyInsertDescData { /* DWARF DIE: 268a05 */
    Relation aoi_rel;
    Snapshot appendOnlyMetaDataSnapshot;
    struct MemTupleBinding * mt_bind;
    File appendFile;
    int appendFilePathNameMaxLen;
    char * appendFilePathName;
    int64 insertCount;
    int64 varblockCount;
    int64 rowCount;
    int64 numSequences;
    int64 lastSequence;
    BlockNumber cur_segno;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    struct FileSegInfo * fsInfo;
    struct VarBlockMaker varBlockMaker;
    int64 bufferCount;
    int64 blockFirstRowNum;
    bool shouldCompress;
    bool usingChecksum;
    bool useNoToast;
    undefined field_0xab;
    int32 completeHeaderLen;
    uint8 * tempSpace;
    uint8 * uncompressedBuffer;
    int32 usableBlockSize;
    int32 maxDataLen;
    int32 tempSpaceLen;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    char * title;
    int32 toast_tuple_threshold;
    int32 toast_tuple_target;
    struct AppendOnlyStorageAttributes storageAttributes;
    struct AppendOnlyStorageWrite storageWrite;
    uint8 * nonCompressedData;
    struct AppendOnlyBlockDirectory blockDirectory;
    bool update_mode;
    undefined field_0x2f9;
    undefined field_0x2fa;
    undefined field_0x2fb;
    undefined field_0x2fc;
    undefined field_0x2fd;
    undefined field_0x2fe;
    undefined field_0x2ff;
};

struct MemTupleAttrBinding { /* DWARF DIE: 2aa6 */
    int offset;
    int len;
    int len_aligned;
    enum MemTupleBindFlag flag;
    int null_byte;
    uchar null_mask;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct mpp_fd_set { /* DWARF DIE: 598364 */
    int32 __fds_bits[2048];
};

struct ProgramPipes { /* DWARF DIE: 20cb4c */
    char * shexec;
    int pipes[2];
    int pid;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct MemTupleData { /* DWARF DIE: 2bc6 */
    uint32 PRIVATE_mt_len;
    uchar PRIVATE_mt_bits[1];
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
};

struct ProjectionInfo { /* DWARF DIE: de0e */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * pi_targetlist;
    struct ExprContext * pi_exprContext;
    struct TupleTableSlot * pi_slot;
    enum ExprDoneCond * pi_itemIsDone;
    bool pi_directMap;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    int pi_numSimpleVars;
    int * pi_varSlotOffsets;
    int * pi_varNumbers;
    int * pi_varOutputCols;
    int pi_lastInnerVar;
    int pi_lastOuterVar;
    int pi_lastScanVar;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
};

struct CdbPathLocus { /* DWARF DIE: b2207 */
    enum CdbLocusType locustype;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * distkey;
    int numsegments;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct Path { /* DWARF DIE: b3c22 */
    enum NodeTag type;
    enum NodeTag pathtype;
    struct RelOptInfo * parent;
    struct ParamPathInfo * param_info;
    double rows;
    Cost startup_cost;
    Cost total_cost;
    EstimatedBytes memory;
    struct CdbPathLocus locus;
    bool motionHazard;
    bool rescannable;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    struct List * pathkeys;
    Relids sameslice_relids;
};

struct PartitionRule { /* DWARF DIE: b31b7 */
    enum NodeTag type;
    Oid parruleid;
    Oid paroid;
    Oid parchildrelid;
    Oid parparentoid;
    bool parisdefault;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    char * parname;
    struct Node * parrangestart;
    bool parrangestartincl;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    struct Node * parrangeend;
    bool parrangeendincl;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    struct Node * parrangeevery;
    struct List * parlistvalues;
    int16 parruleord;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    struct List * parreloptions;
    Oid partemplatespaceId;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    struct PartitionNode * children;
};

struct MinipageEntry { /* DWARF DIE: 11465d */
    int64 firstRowNum;
    int64 fileOffset;
    int64 rowCount;
};

struct CdbDispatchResults { /* DWARF DIE: 283c59 */
    struct CdbDispatchResult * resultArray;
    int resultCount;
    int resultCapacity;
    int iFirstError;
    int errcode;
    bool cancelOnError;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct CdbDispatchResults_SliceInfo * sliceMap;
    int sliceCapacity;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
};

struct CdbComponentDatabaseInfo { /* DWARF DIE: 20c7f3 */
    struct GpSegConfigEntry * config;
    struct CdbComponentDatabases * cdbs;
    int16 hostSegs;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    struct List * freelist;
    int numIdleQEs;
    int numActiveQEs;
};

struct Bitmapset { /* DWARF DIE: a76b */
    int nwords;
    bitmapword words[1];
};

struct CdbExplain_DispatchSummary { /* DWARF DIE: 525d80 */
    int nResult;
    int nOk;
    int nError;
    int nCanceled;
    int nNotDispatched;
    int nIgnorableError;
};

struct ItemPointerData { /* DWARF DIE: cf4 */
    struct BlockIdData ip_blkid;
    OffsetNumber ip_posid;
};

struct TupleVisibilitySummary { /* DWARF DIE: df44a */
    struct ItemPointerData tid;
    int16 infomask;
    int16 infomask2;
    struct ItemPointerData updateTid;
    TransactionId xmin;
    enum TupleTransactionStatus xminStatus;
    TransactionId xmax;
    enum TupleTransactionStatus xmaxStatus;
    CommandId cid;
    enum TupleVisibilityStatus visibilityStatus;
};

struct FunctionCallInfoData { /* DWARF DIE: 25ce */
    struct FmgrInfo * flinfo;
    fmNodePtr context;
    fmNodePtr resultinfo;
    Oid fncollation;
    bool isnull;
    undefined field_0x1d;
    short nargs;
    Datum arg[100];
    bool argnull[100];
    undefined field_0x3a4;
    undefined field_0x3a5;
    undefined field_0x3a6;
    undefined field_0x3a7;
};

struct RelationAmInfo { /* DWARF DIE: b8a9 */
    struct FmgrInfo aminsert;
    struct FmgrInfo ambeginscan;
    struct FmgrInfo amgettuple;
    struct FmgrInfo amgetbitmap;
    struct FmgrInfo amrescan;
    struct FmgrInfo amendscan;
    struct FmgrInfo ammarkpos;
    struct FmgrInfo amrestrpos;
    struct FmgrInfo amcanreturn;
};

struct StringInfoData { /* DWARF DIE: 880f */
    char * data;
    int len;
    int maxlen;
    int cursor;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct pgresParamDesc { /* DWARF DIE: 4d7b68 */
    Oid typid;
};

struct TriggerDesc { /* DWARF DIE: b753 */
    struct Trigger * triggers;
    int numtriggers;
    bool trig_insert_before_row;
    bool trig_insert_after_row;
    bool trig_insert_instead_row;
    bool trig_insert_before_statement;
    bool trig_insert_after_statement;
    bool trig_update_before_row;
    bool trig_update_after_row;
    bool trig_update_instead_row;
    bool trig_update_before_statement;
    bool trig_update_after_statement;
    bool trig_delete_before_row;
    bool trig_delete_after_row;
    bool trig_delete_instead_row;
    bool trig_delete_before_statement;
    bool trig_delete_after_statement;
    bool trig_truncate_before_statement;
    bool trig_truncate_after_statement;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
};

struct AOCSVPInfoEntry { /* DWARF DIE: 1144f1 */
    int64 eof;
    int64 eof_uncompressed;
};

struct AOCSVPInfo { /* DWARF DIE: 114521 */
    int32 _len;
    int32 version;
    int32 nEntry;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct AOCSVPInfoEntry entry[1];
};

struct int2vector { /* DWARF DIE: 7f68 */
    int32 vl_len_;
    int ndim;
    int32 dataoffset;
    Oid elemtype;
    int dim1;
    int lbound1;
    int16 values[1];
    undefined field_0x1a;
    undefined field_0x1b;
};

struct ForeignTable { /* DWARF DIE: b3467 */
    Oid relid;
    Oid serverid;
    struct List * options;
    char exec_location;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct varlena { /* DWARF DIE: 4d34 */
    char vl_len_[4];
    char vl_dat[1];
};

struct CdbDispatchResult { /* DWARF DIE: 285238 */
    struct SegmentDatabaseDescriptor * segdbDesc;
    struct CdbDispatchResults * meleeResults;
    int meleeIndex;
    int errcode;
    int okindex;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct PQExpBufferData * resultbuf;
    struct PQExpBufferData * error_message;
    bool hasDispatched;
    bool stillRunning;
    undefined field_0x32;
    undefined field_0x33;
    enum DispatchWaitMode sentSignal;
    bool wasCanceled;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    int numrowsrejected;
    int numrowscompleted;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
};

struct PartitionAccessMethods { /* DWARF DIE: e1b3 */
    int partLevels;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    void * * amstate;
    MemoryContext part_cxt;
};

struct CdbSreh { /* DWARF DIE: 20cbc5 */
    char * errmsg;
    char * rawdata;
    char * relname;
    int64 linenumber;
    uint64 processed;
    bool is_server_enc;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    int rejectlimit;
    int rejectcount;
    bool is_limit_in_rows;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    MemoryContext badrowcontext;
    char filename[1024];
    bool log_to_file;
    undefined field_0x441;
    undefined field_0x442;
    undefined field_0x443;
    Oid relid;
};

struct CdbExplain_SliceWorker { /* DWARF DIE: 525cb0 */
    double peakmemused;
    double vmem_reserved;
    double memory_accounting_global_peak;
};

struct List { /* DWARF DIE: 9c41 */
    enum NodeTag type;
    int length;
    struct ListCell * head;
    struct ListCell * tail;
};

struct ScanKeyData { /* DWARF DIE: 18dc5 */
    int sk_flags;
    AttrNumber sk_attno;
    StrategyNumber sk_strategy;
    Oid sk_subtype;
    Oid sk_collation;
    struct FmgrInfo sk_func;
    Datum sk_argument;
};

struct ParamExternData { /* DWARF DIE: bbbc */
    Datum value;
    bool isnull;
    undefined field_0x9;
    uint16 pflags;
    Oid ptype;
};

struct IntoClause { /* DWARF DIE: c01a */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct RangeVar * rel;
    struct List * colNames;
    struct List * options;
    enum OnCommitAction onCommit;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    char * tableSpaceName;
    struct Node * viewQuery;
    bool skipData;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    struct Node * distributedBy;
};

struct dlist_node { /* DWARF DIE: a3d6 */
    struct dlist_node * prev;
    struct dlist_node * next;
};

struct pgLobjfuncs { /* DWARF DIE: 4d7e5a */
    Oid fn_lo_open;
    Oid fn_lo_close;
    Oid fn_lo_creat;
    Oid fn_lo_create;
    Oid fn_lo_unlink;
    Oid fn_lo_lseek;
    Oid fn_lo_lseek64;
    Oid fn_lo_tell;
    Oid fn_lo_tell64;
    Oid fn_lo_truncate;
    Oid fn_lo_truncate64;
    Oid fn_lo_read;
    Oid fn_lo_write;
};

struct ModifyTable { /* DWARF DIE: 4999c2 */
    struct Plan plan;
    enum CmdType operation;
    bool canSetTag;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    struct List * resultRelations;
    int resultRelIndex;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    struct List * plans;
    struct List * withCheckOptionLists;
    struct List * returningLists;
    struct List * fdwPrivLists;
    struct List * rowMarks;
    int epqParam;
    undefined field_0xe4;
    undefined field_0xe5;
    undefined field_0xe6;
    undefined field_0xe7;
    struct List * action_col_idxes;
    struct List * ctid_col_idxes;
    struct List * oid_col_idxes;
};

struct sockaddr_storage { /* DWARF DIE: 8070 */
    sa_family_t ss_family;
    char __ss_padding[118];
    ulong __ss_align;
};

struct pgNotify { /* DWARF DIE: 4d78a2 */
    char * relname;
    int be_pid;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    char * extra;
    struct pgNotify * next;
};

struct LockInfoData { /* DWARF DIE: b885 */
    struct LockRelId lockRelId;
};

struct CommonTableExpr { /* DWARF DIE: ca39 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * ctename;
    struct List * aliascolnames;
    struct Node * ctequery;
    int location;
    bool cterecursive;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    int cterefcount;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    struct List * ctecolnames;
    struct List * ctecoltypes;
    struct List * ctecoltypmods;
    struct List * ctecolcollations;
};

struct ColumnRef { /* DWARF DIE: c602 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * fields;
    int location;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct AOCSFileSegInfo { /* DWARF DIE: 114579 */
    struct TupleVisibilitySummary tupleVisibilitySummary;
    int32 segno;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    int64 total_tupcount;
    int64 varblockcount;
    int64 modcount;
    enum FileSegInfoState state;
    int16 formatversion;
    undefined field_0x4e;
    undefined field_0x4f;
    struct AOCSVPInfo vpinfo;
};

struct BufferAccessStrategyData { /* DWARF DIE: 5ed2a */
};

struct tupleConstr { /* DWARF DIE: 1e24 */
    AttrDefault * defval;
    ConstrCheck * check;
    uint16 num_defval;
    uint16 num_check;
    bool has_not_null;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct QualCost { /* DWARF DIE: b34c5 */
    Cost startup;
    Cost per_tuple;
};

struct CdbDispatcherState { /* DWARF DIE: 1a639d */
    bool isExtendedQuery;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * allocatedGangs;
    bool destroyGang;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    struct CdbDispatchResults * primaryResults;
    void * dispatchParams;
    int largestGangSize;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
};

struct BulkInsertStateData { /* DWARF DIE: dc5c8 */
    BufferAccessStrategy strategy;
    Buffer current_buf;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct CdbComponentDatabases { /* DWARF DIE: 20c853 */
    struct CdbComponentDatabaseInfo * segment_db_info;
    int total_segment_dbs;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct CdbComponentDatabaseInfo * entry_db_info;
    int total_entry_dbs;
    int total_segments;
    uint8 fts_version;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    int expand_version;
    int numActiveQEs;
    int numIdleQEs;
    int qeCounter;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    struct List * freeCounterList;
};

struct SMgrRelationData { /* DWARF DIE: a401 */
    struct RelFileNodeBackend smgr_rnode;
    struct SMgrRelationData * * smgr_owner;
    BlockNumber smgr_targblock;
    BlockNumber smgr_fsm_nblocks;
    BlockNumber smgr_vm_nblocks;
    int smgr_which;
    struct _MdfdVec * md_fd[4];
    struct dlist_node node;
};

struct DistributedSnapshot { /* DWARF DIE: b9d8 */
    DistributedTransactionTimeStamp distribTransactionTimeStamp;
    DistributedTransactionId xminAllDistributedSnapshots;
    DistributedSnapshotId distribSnapshotId;
    DistributedTransactionId xmin;
    DistributedTransactionId xmax;
    int32 count;
    int32 maxCount;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    DistributedTransactionId * inProgressXidArray;
};

struct DistributedSnapshotWithLocalMapping { /* DWARF DIE: ba56 */
    struct DistributedSnapshot ds;
    TransactionId minCachedLocalXid;
    TransactionId maxCachedLocalXid;
    int32 currentLocalXidsCount;
    int32 maxLocalXidsCount;
    TransactionId * inProgressMappedLocalXids;
};

struct ApplyShareInputContext { /* DWARF DIE: b34f5 */
    struct List * curr_rtable;
    int * share_refcounts;
    int share_refcounts_sz;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    struct List * motStack;
    struct List * qdShares;
    struct List * qdSlices;
    int nextPlanId;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    struct ShareInputScan * * producers;
    int * sliceMarks;
    int producer_count;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
};

struct PlannerGlobal { /* DWARF DIE: b3591 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    ParamListInfo boundParams;
    struct List * subplans;
    struct List * subroots;
    struct Bitmapset * rewindPlanIDs;
    struct List * finalrtable;
    struct List * finalrowmarks;
    struct List * resultRelations;
    struct List * relationOids;
    struct List * invalItems;
    int nParamExec;
    Index lastPHId;
    Index lastRowMarkId;
    bool transientPlan;
    bool oneoffPlan;
    bool simplyUpdatable;
    undefined field_0x5f;
    struct ApplyShareInputContext share;
};

struct SegmentDatabaseDescriptor { /* DWARF DIE: 4df596 */
    struct CdbComponentDatabaseInfo * segment_database_info;
    int32 segindex;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    PGconn * conn;
    uint32 motionListener;
    int32 backendPid;
    char * whoami;
    bool isWriter;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    int identifier;
};

struct DynamicTableScanInfo { /* DWARF DIE: e241 */
    int numScans;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * numSelectorsPerScanId;
    struct HTAB * * pidIndexes;
    Oid * curRelOids;
    struct List * partsMetadata;
};

struct Partition { /* DWARF DIE: b3d5c */
    enum NodeTag type;
    Oid partid;
    Oid parrelid;
    char parkind;
    undefined field_0xd;
    int16 parlevel;
    bool paristemplate;
    undefined field_0x11;
    int16 parnatts;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    AttrNumber * paratts;
    Oid * parclass;
};

struct QueryDesc { /* DWARF DIE: e61f */
    enum CmdType operation;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct PlannedStmt * plannedstmt;
    struct Node * utilitystmt;
    char * sourceText;
    Snapshot snapshot;
    Snapshot crosscheck_snapshot;
    DestReceiver * dest;
    ParamListInfo params;
    int instrument_options;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    TupleDesc tupDesc;
    struct EState * estate;
    struct PlanState * planstate;
    uint64 es_processed;
    Oid es_lastoid;
    bool extended_query;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    char * portal_name;
    struct QueryDispatchDesc * ddesc;
    struct CdbExplain_ShowStatCtx * showstatctx;
    struct gpmon_packet_t * gpmon_pkt;
    struct Instrumentation * totaltime;
    MemoryAccountIdType memoryAccountId;
};

struct URL_FILE { /* DWARF DIE: 20c33c */
    enum fcurl_type_e type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * url;
};

struct TupleTableSlot { /* DWARF DIE: 304c */
    enum NodeTag type;
    int PRIVATE_tts_flags;
    HeapTuple PRIVATE_tts_heaptuple;
    void * PRIVATE_tts_htup_buf;
    uint32 PRIVATE_tts_htup_buf_len;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    MemTuple PRIVATE_tts_memtuple;
    void * PRIVATE_tts_mtup_buf;
    uint32 PRIVATE_tts_mtup_buf_len;
    struct ItemPointerData PRIVATE_tts_synthetic_ctid;
    undefined field_0x3a;
    undefined field_0x3b;
    int PRIVATE_tts_nvalid;
    long PRIVATE_tts_off;
    bool PRIVATE_tts_slow;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    Datum * PRIVATE_tts_values;
    bool * PRIVATE_tts_isnull;
    TupleDesc tts_tupleDescriptor;
    struct MemTupleBinding * tts_mt_bind;
    MemoryContext tts_mcxt;
    Buffer tts_buffer;
    Oid tts_tableOid;
};

struct CdbExplain_ShowStatCtx { /* DWARF DIE: 5203f8 */
    struct StringInfoData extratextbuf;
    instr_time querystarttime;
    double workmemused_max;
    double workmemwanted_max;
    bool stats_gathered;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    int nslice;
    struct CdbExplain_SliceSummary * slices;
};

struct JunkFilter { /* DWARF DIE: ded7 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * jf_targetList;
    TupleDesc jf_cleanTupType;
    AttrNumber * jf_cleanMap;
    struct TupleTableSlot * jf_resultSlot;
    AttrNumber jf_junkAttNo;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
};

struct MemoryContextMethods { /* DWARF DIE: f1e4 */
    void * (* alloc)(MemoryContext, Size);
    void (* free_p)(MemoryContext, void *);
    void * (* realloc)(MemoryContext, void *, Size);
    void (* init)(MemoryContext);
    void (* reset)(MemoryContext);
    void (* delete_context)(MemoryContext);
    Size (* get_chunk_space)(MemoryContext, void *);
    bool (* is_empty)(MemoryContext);
    void (* stats)(MemoryContext, uint64 *, uint64 *, uint64 *, uint64 *, uint64 *, uint64 *);
    void (* release_accounting)(MemoryContext);
};

struct RewriteRule { /* DWARF DIE: b5d3 */
    Oid ruleId;
    enum CmdType event;
    struct Node * qual;
    struct List * actions;
    char enabled;
    bool isInstead;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
};

struct ChunkTransportState { /* DWARF DIE: 5969de */
    int size;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct ChunkTransportStateEntry * states;
    bool activated;
    bool aggressiveRetry;
    bool teardownActive;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    struct List * incompleteConns;
    struct SliceTable * sliceTable;
    int sliceId;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    struct EState * estate;
    bool (* SendChunk)(struct ChunkTransportState *, struct ChunkTransportStateEntry *, struct MotionConn *, TupleChunkListItem, int16);
    TupleChunkListItem (* RecvTupleChunkFrom)(struct ChunkTransportState *, int16, int16);
    TupleChunkListItem (* RecvTupleChunkFromAny)(struct ChunkTransportState *, int16, int16 *);
    void (* doSendStopMessage)(struct ChunkTransportState *, int16);
    void (* SendEos)(struct ChunkTransportState *, int, TupleChunkListItem);
};

struct ParamExecData { /* DWARF DIE: be67 */
    void * execPlan;
    Datum value;
    bool isnull;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct AOCSInsertDescData { /* DWARF DIE: 2bcec9 */
    Relation aoi_rel;
    Snapshot appendOnlyMetaDataSnapshot;
    struct AOCSFileSegInfo * fsInfo;
    int64 insertCount;
    int64 varblockCount;
    int64 rowCount;
    int64 numSequences;
    int64 lastSequence;
    int32 cur_segno;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    char * compType;
    int32 compLevel;
    int32 blocksz;
    struct DatumStreamWrite * * ds;
    struct AppendOnlyBlockDirectory blockDirectory;
    bool update_mode;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
};

struct Param { /* DWARF DIE: c15d */
    struct Expr xpr;
    enum ParamKind paramkind;
    int paramid;
    Oid paramtype;
    int32 paramtypmod;
    Oid paramcollid;
    int location;
};

struct RangeTblEntry { /* DWARF DIE: c758 */
    enum NodeTag type;
    enum RTEKind rtekind;
    Oid relid;
    char relkind;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct Query * subquery;
    bool security_barrier;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct Plan * subquery_plan;
    struct List * subquery_rtable;
    struct List * subquery_pathkeys;
    enum JoinType jointype;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    struct List * joinaliasvars;
    struct List * functions;
    bool funcordinality;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    struct List * values_lists;
    struct List * values_collations;
    char * ctename;
    Index ctelevelsup;
    bool self_reference;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    struct List * ctecoltypes;
    struct List * ctecoltypmods;
    struct List * ctecolcollations;
    bool forceDistRandom;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    struct Alias * alias;
    struct Alias * eref;
    bool lateral;
    bool inh;
    bool inFromCl;
    undefined field_0xab;
    AclMode requiredPerms;
    Oid checkAsUser;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    struct Bitmapset * selectedCols;
    struct Bitmapset * modifiedCols;
    struct List * securityQuals;
    struct List * pseudocols;
};

struct LockingClause { /* DWARF DIE: c6bb */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * lockedRels;
    enum LockClauseStrength strength;
    bool noWait;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

union anon_union_for_t_field3 { /* DWARF DIE: 299b */
    CommandId t_cid;
    TransactionId t_xvac;
};

struct HeapTupleFields { /* DWARF DIE: 29ba */
    TransactionId t_xmin;
    TransactionId t_xmax;
    union anon_union_for_t_field3 t_field3;
};

struct DatumTupleFields { /* DWARF DIE: 29f6 */
    int32 datum_len_;
    int32 datum_typmod;
    Oid datum_typeid;
};

union anon_union_for_t_choice { /* DWARF DIE: 2a32 */
    struct HeapTupleFields t_heap;
    struct DatumTupleFields t_datum;
};

struct _DestReceiver { /* DWARF DIE: e512 */
    void (* receiveSlot)(struct TupleTableSlot *, DestReceiver *);
    void (* rStartup)(DestReceiver *, int, TupleDesc);
    void (* rShutdown)(DestReceiver *);
    void (* rDestroy)(DestReceiver *);
    enum CommandDest mydest;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
};

struct CdbExplain_Agg { /* DWARF DIE: 522036 */
    double vmax;
    double vsum;
    int vcnt;
    int imax;
};

struct pgresAttValue { /* DWARF DIE: 4d7b8c */
    int len;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * value;
};

struct nameData { /* DWARF DIE: 4d6 */
    char data[64];
};

struct FormData_pg_class { /* DWARF DIE: b389 */
    NameData relname;
    Oid relnamespace;
    Oid reltype;
    Oid reloftype;
    Oid relowner;
    Oid relam;
    Oid relfilenode;
    Oid reltablespace;
    int32 relpages;
    float4 reltuples;
    int32 relallvisible;
    Oid reltoastrelid;
    bool relhasindex;
    bool relisshared;
    char relpersistence;
    char relkind;
    char relstorage;
    undefined field_0x71;
    int16 relnatts;
    int16 relchecks;
    bool relhasoids;
    bool relhaspkey;
    bool relhasrules;
    bool relhastriggers;
    bool relhassubclass;
    bool relispopulated;
    char relreplident;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    TransactionId relfrozenxid;
    TransactionId relminmxid;
};

struct PlannerConfig { /* DWARF DIE: b330b */
    bool enable_sort;
    bool enable_hashagg;
    bool enable_groupagg;
    bool enable_nestloop;
    bool enable_mergejoin;
    bool enable_hashjoin;
    bool gp_enable_hashjoin_size_heuristic;
    bool gp_enable_predicate_propagation;
    int constraint_exclusion;
    bool gp_enable_minmax_optimization;
    bool gp_enable_multiphase_agg;
    bool gp_enable_preunique;
    bool gp_eager_preunique;
    bool gp_hashagg_streambottom;
    bool gp_enable_agg_distinct;
    bool gp_enable_dqa_pruning;
    bool gp_eager_dqa_pruning;
    bool gp_eager_one_phase_agg;
    bool gp_eager_two_phase_agg;
    bool gp_enable_groupext_distinct_pruning;
    bool gp_enable_groupext_distinct_gather;
    bool gp_enable_sort_distinct;
    bool gp_enable_direct_dispatch;
    bool gp_dynamic_partition_pruning;
    bool gp_cte_sharing;
    bool honor_order_by;
    bool is_under_subplan;
    undefined field_0x1e;
    undefined field_0x1f;
};

struct EPQState { /* DWARF DIE: 49bb29 */
    struct EState * estate;
    struct PlanState * planstate;
    struct TupleTableSlot * origslot;
    struct Plan * plan;
    struct List * arowMarks;
    int epqParam;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
};

struct ModifyTableState { /* DWARF DIE: 49bb97 */
    struct PlanState ps;
    enum CmdType operation;
    bool canSetTag;
    bool mt_done;
    undefined field_0x206;
    undefined field_0x207;
    struct PlanState * * mt_plans;
    int mt_nplans;
    int mt_whichplan;
    struct ResultRelInfo * resultRelInfo;
    struct List * * mt_arowmarks;
    struct EPQState mt_epqstate;
    bool fireBSTriggers;
    undefined field_0x259;
    undefined field_0x25a;
    undefined field_0x25b;
    undefined field_0x25c;
    undefined field_0x25d;
    undefined field_0x25e;
    undefined field_0x25f;
    AttrNumber * mt_action_col_idxes;
    AttrNumber * mt_ctid_col_idxes;
    AttrNumber * mt_oid_col_idxes;
};

struct _MdfdVec { /* DWARF DIE: a490 */
};

struct HeapTupleData { /* DWARF DIE: 1009 */
    uint32 t_len;
    struct ItemPointerData t_self;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    HeapTupleHeader t_data;
};

struct CopyIntoClause { /* DWARF DIE: c0a4 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * attlist;
    bool is_program;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    char * filename;
    struct List * options;
    struct List * ao_segnos;
};

struct SockAddr { /* DWARF DIE: e991 */
    struct sockaddr_storage addr;
    socklen_t salen;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
};

struct ChunkTransportStateEntry { /* DWARF DIE: 5988fb */
    int motNodeId;
    bool valid;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct MotionConn * conns;
    int numConns;
    struct mpp_fd_set readSet;
    int highReadSock;
    int scanStart;
    undefined field_0x201c;
    undefined field_0x201d;
    undefined field_0x201e;
    undefined field_0x201f;
    struct Slice * sendSlice;
    struct Slice * recvSlice;
    int txfd;
    int txfd_family;
    ushort txport;
    bool sendingEos;
    undefined field_0x203b;
    undefined field_0x203c;
    undefined field_0x203d;
    undefined field_0x203e;
    undefined field_0x203f;
    uint64 stat_total_ack_time;
    uint64 stat_count_acks;
    uint64 stat_max_ack_time;
    uint64 stat_min_ack_time;
    uint64 stat_count_resent;
    uint64 stat_max_resent;
    uint64 stat_count_dropped;
};

struct RuleLock { /* DWARF DIE: b639 */
    int numLocks;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct RewriteRule * * rules;
};

struct HeapTupleHeaderData { /* DWARF DIE: f2b */
    union anon_union_for_t_choice t_choice;
    struct ItemPointerData t_ctid;
    uint16 t_infomask2;
    uint16 t_infomask;
    uint8 t_hoff;
    bits8 t_bits[1];
};

struct PgStat_TableXactStatus { /* DWARF DIE: 5594c */
    PgStat_Counter tuples_inserted;
    PgStat_Counter tuples_updated;
    PgStat_Counter tuples_deleted;
    int nest_level;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct PgStat_TableXactStatus * upper;
    struct PgStat_TableStatus * parent;
    struct PgStat_TableXactStatus * next;
};

struct addrinfo { /* DWARF DIE: 4d6985 */
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    socklen_t ai_addrlen;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    struct sockaddr * ai_addr;
    char * ai_canonname;
    struct addrinfo * ai_next;
};

struct SliceTable { /* DWARF DIE: e2ae */
    enum NodeTag type;
    int nMotions;
    int nInitPlans;
    int localSlice;
    struct List * slices;
    int instrument_options;
    uint32 ic_instance_id;
};

union anon_union_for_data { /* DWARF DIE: 9c94 */
    void * ptr_value;
    int int_value;
    Oid oid_value;
};

struct ListCell { /* DWARF DIE: 9c1c */
    union anon_union_for_data data;
    struct ListCell * next;
};

struct sockaddr { /* DWARF DIE: 518 */
    sa_family_t sa_family;
    char sa_data[14];
};

struct ParamRef { /* DWARF DIE: c643 */
    enum NodeTag type;
    int number;
    int location;
};

struct PQExpBufferData { /* DWARF DIE: 4d7af8 */
    char * data;
    size_t len;
    size_t maxlen;
};

struct ICBuffer { /* DWARF DIE: 59876d */
    struct ICBufferLink primary;
    struct ICBufferLink secondary;
    struct MotionConn * conn;
    uint64 sentTime;
    uint32 nRetry;
    int32 unackQueueRingSlot;
    struct icpkthdr pkt[0];
};

struct FileSegInfo { /* DWARF DIE: 11446d */
    struct TupleVisibilitySummary tupleVisibilitySummary;
    int segno;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    int64 total_tupcount;
    int64 varblockcount;
    int64 modcount;
    int64 eof;
    int64 eof_uncompressed;
    int16 formatversion;
    undefined field_0x5a;
    undefined field_0x5b;
    enum FileSegInfoState state;
};

struct CdbExplain_SliceSummary { /* DWARF DIE: 525e01 */
    struct Slice * slice;
    int nworker;
    int segindex0;
    struct CdbExplain_SliceWorker * workers;
    void * * memoryAccounts;
    MemoryAccountIdType * memoryAccountCount;
    struct CdbExplain_Agg peakmemused;
    struct CdbExplain_Agg vmem_reserved;
    struct CdbExplain_Agg memory_accounting_global_peak;
    double workmemused_max;
    double workmemwanted_max;
    struct CdbExplain_DispatchSummary dispatchSummary;
};

struct PlannerInfo { /* DWARF DIE: b3675 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct Query * parse;
    struct PlannerGlobal * glob;
    Index query_level;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct PlannerInfo * parent_root;
    struct List * plan_params;
    struct RelOptInfo * * simple_rel_array;
    int simple_rel_array_size;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    struct RangeTblEntry * * simple_rte_array;
    Relids all_baserels;
    Relids nullable_baserels;
    struct List * join_rel_list;
    struct HTAB * join_rel_hash;
    struct List * * join_rel_level;
    int join_cur_level;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    struct List * init_plans;
    struct List * cte_plan_ids;
    struct List * eq_classes;
    struct List * non_eq_clauses;
    struct List * canon_pathkeys;
    struct PartitionNode * result_partitions;
    struct List * result_aosegnos;
    struct List * list_cteplaninfo;
    struct List * left_join_clauses;
    struct List * right_join_clauses;
    struct List * full_join_clauses;
    struct List * join_info_list;
    struct List * lateral_info_list;
    struct List * append_rel_list;
    struct List * rowMarks;
    struct List * placeholder_list;
    struct List * query_pathkeys;
    struct List * group_pathkeys;
    struct List * window_pathkeys;
    struct List * distinct_pathkeys;
    struct List * sort_pathkeys;
    struct List * minmax_aggs;
    struct List * initial_rels;
    MemoryContext planner_cxt;
    double total_table_pages;
    double tuple_fraction;
    double limit_tuples;
    bool hasInheritedTarget;
    bool hasJoinRTEs;
    bool hasLateralRTEs;
    bool hasHavingQual;
    bool hasPseudoConstantQuals;
    bool hasRecursion;
    undefined field_0x156;
    undefined field_0x157;
    int wt_param_id;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    struct Plan * non_recursive_plan;
    Relids curOuterRels;
    struct List * curOuterParams;
    struct PlannerConfig * config;
    struct List * dynamicScans;
    void * join_search_private;
    int upd_del_replicated_table;
    bool is_split_update;
    bool is_correlated_subplan;
    undefined field_0x196;
    undefined field_0x197;
};

struct Minipage { /* DWARF DIE: 114699 */
    int32 _len;
    int32 version;
    uint32 nEntry;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct MinipageEntry entry[1];
};

struct ExplainStateExtra { /* DWARF DIE: 4f085e */
    struct List * groupingstack;
    struct List * deparsecxt;
};

struct GpPolicy { /* DWARF DIE: b93d */
    enum NodeTag type;
    enum GpPolicyType ptype;
    int numsegments;
    int nattrs;
    AttrNumber * attrs;
    Oid * opclasses;
};

struct FormData_pg_appendonly { /* DWARF DIE: b2c5 */
    Oid relid;
    int32 blocksize;
    int32 safefswritesize;
    int16 compresslevel;
    bool checksum;
    NameData compresstype;
    bool columnstore;
    Oid segrelid;
    Oid blkdirrelid;
    Oid blkdiridxid;
    Oid visimaprelid;
    Oid visimapidxid;
};

struct DatumStreamTypeInfo { /* DWARF DIE: 1157de */
    int32 datumlen;
    int32 typid;
    char align;
    bool byval;
    undefined field_0xa;
    undefined field_0xb;
};

struct FdwRoutine { /* DWARF DIE: 4983a1 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    GetForeignRelSize_function GetForeignRelSize;
    GetForeignPaths_function GetForeignPaths;
    ForeignScan * (* GetForeignPlan)(struct PlannerInfo *, struct RelOptInfo *, Oid, struct ForeignPath *, struct List *, struct List *);
    void (* BeginForeignScan)(struct ForeignScanState *, int);
    TupleTableSlot * (* IterateForeignScan)(struct ForeignScanState *);
    ReScanForeignScan_function ReScanForeignScan;
    EndForeignScan_function EndForeignScan;
    void (* AddForeignUpdateTargets)(struct Query *, struct RangeTblEntry *, Relation);
    List * (* PlanForeignModify)(struct PlannerInfo *, struct ModifyTable *, Index, int);
    void (* BeginForeignModify)(struct ModifyTableState *, struct ResultRelInfo *, struct List *, int, int);
    ExecForeignInsert_function ExecForeignInsert;
    ExecForeignUpdate_function ExecForeignUpdate;
    ExecForeignDelete_function ExecForeignDelete;
    void (* EndForeignModify)(struct EState *, struct ResultRelInfo *);
    int (* IsForeignRelUpdatable)(Relation);
    void (* ExplainForeignScan)(struct ForeignScanState *, struct ExplainState *);
    void (* ExplainForeignModify)(struct ModifyTableState *, struct ResultRelInfo *, struct List *, int, struct ExplainState *);
    bool (* AnalyzeForeignTable)(Relation, int (** )(Relation, int, HeapTuple *, int, double *, double *), BlockNumber *);
};

struct PartitionNode { /* DWARF DIE: b28c8 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct Partition * part;
    struct PartitionRule * default_part;
    struct List * rules;
};

struct pgDataValue { /* DWARF DIE: 4d7f1d */
    int len;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * value;
};

struct Flow { /* DWARF DIE: c2d5 */
    enum NodeTag type;
    enum FlowType flotype;
    enum Movement req_move;
    enum CdbLocusType locustype;
    int segindex;
    int numsegments;
    struct List * hashExprs;
    struct List * hashOpfamilies;
    AttrNumber segidColIdx;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    struct Flow * flow_before_req_move;
};

struct DatumStreamBlockWrite { /* DWARF DIE: 2bc658 */
    char eyecatcher[4];
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct DatumStreamTypeInfo * typeInfo;
    enum DatumStreamVersion datumStreamVersion;
    bool rle_want_compression;
    bool delta_want_compression;
    undefined field_0x16;
    undefined field_0x17;
    int32 initialMaxDatumPerBlock;
    int32 maxDatumPerBlock;
    int32 maxDataBlockSize;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    int (* errdetailCallback)(void *);
    void * errdetailArg;
    int (* errcontextCallback)(void *);
    void * errcontextArg;
    int32 nth;
    int32 physical_datum_count;
    bool has_null;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    struct DatumStreamBitMapWrite null_bitmap;
    uint8 * datump;
    int32 always_null_bitmap_count;
    bool rle_has_compression;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    uint8 * rle_last_item;
    int32 rle_last_item_size;
    bool rle_last_item_is_repeated;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    int32 rle_total_repeat_items_written;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    struct DatumStreamBitMapWrite rle_compress_bitmap;
    int32 rle_repeatcounts_count;
    int32 rle_repeatcounts_current_size;
    bool delta_has_compression;
    bool not_first_datum;
    undefined field_0xca;
    undefined field_0xcb;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
    Datum compare_item;
    struct DatumStreamBitMapWrite delta_bitmap;
    int32 deltas_count;
    int32 deltas_current_size;
    MemoryContext memctxt;
    uint8 * null_bitmap_buffer;
    int null_bitmap_buffer_size;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    uint8 * datum_buffer;
    int32 datum_buffer_size;
    undefined field_0x124;
    undefined field_0x125;
    undefined field_0x126;
    undefined field_0x127;
    uint8 * datum_afterp;
    uint8 * rle_compress_bitmap_buffer;
    int32 rle_compress_bitmap_buffer_size;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    int32 * rle_repeatcounts;
    int32 rle_repeatcounts_maxcount;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    uint8 * delta_bitmap_buffer;
    int32 delta_bitmap_buffer_size;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    int32 * deltas;
    bool * delta_sign;
    int32 deltas_maxcount;
    undefined field_0x174;
    undefined field_0x175;
    undefined field_0x176;
    undefined field_0x177;
    int64 savings;
    int64 remember_savings;
};

struct FormatterData { /* DWARF DIE: 20c240 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    Relation fmt_relation;
    TupleDesc fmt_tupDesc;
    struct List * fmt_args;
    enum FmtNotification fmt_notification;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    HeapTuple fmt_tuple;
    struct StringInfoData fmt_databuf;
    bool fmt_saw_eof;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    struct FmgrInfo * fmt_conv_funcs;
    Oid * fmt_typioparams;
    MemoryContext fmt_perrow_ctx;
    void * fmt_user_ctx;
    int fmt_badrow_num;
    int fmt_badrow_len;
    char * fmt_badrow_data;
    int fmt_bytesread;
    bool fmt_needs_transcoding;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    struct FmgrInfo * fmt_conversion_proc;
    int fmt_external_encoding;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
};

struct AttrMap { /* DWARF DIE: 942ae */
    int live_count;
    int attr_max;
    int attr_count;
    AttrNumber attr_map[1];
    undefined field_0xe;
    undefined field_0xf;
};

struct ExprState { /* DWARF DIE: 20b913 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct Expr * expr;
    Datum (* evalfunc)(struct ExprState *, struct ExprContext *, bool *, enum ExprDoneCond *);
};

struct ParamPathInfo { /* DWARF DIE: b3d08 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    Relids ppi_req_outer;
    double ppi_rows;
    struct List * ppi_clauses;
};

struct FormData_pg_attribute { /* DWARF DIE: 1061 */
    Oid attrelid;
    NameData attname;
    Oid atttypid;
    int32 attstattarget;
    int16 attlen;
    int16 attnum;
    int32 attndims;
    int32 attcacheoff;
    int32 atttypmod;
    bool attbyval;
    char attstorage;
    char attalign;
    bool attnotnull;
    bool atthasdef;
    bool attisdropped;
    bool attislocal;
    undefined field_0x63;
    int32 attinhcount;
    Oid attcollation;
};

struct FromExpr { /* DWARF DIE: c251 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct List * fromlist;
    struct Node * quals;
};

struct RelOptInfo { /* DWARF DIE: b3981 */
    enum NodeTag type;
    enum RelOptKind reloptkind;
    Relids relids;
    double rows;
    int width;
    bool onerow;
    bool consider_startup;
    bool consider_param_startup;
    undefined field_0x1f;
    struct List * reltargetlist;
    struct List * pathlist;
    struct List * ppilist;
    struct Path * cheapest_startup_path;
    struct Path * cheapest_total_path;
    struct Path * cheapest_unique_path;
    struct List * cheapest_parameterized_paths;
    Index relid;
    Oid reltablespace;
    enum RTEKind rtekind;
    AttrNumber min_attr;
    AttrNumber max_attr;
    Relids * attr_needed;
    int32 * attr_widths;
    struct List * lateral_vars;
    Relids lateral_relids;
    Relids lateral_referencers;
    struct List * indexlist;
    BlockNumber pages;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    double tuples;
    struct GpPolicy * cdbpolicy;
    char relstorage;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    undefined field_0xb4;
    undefined field_0xb5;
    undefined field_0xb6;
    undefined field_0xb7;
    double allvisfrac;
    struct Plan * subplan;
    struct PlannerInfo * subroot;
    struct List * subplan_params;
    struct FdwRoutine * fdwroutine;
    void * fdw_private;
    struct ExtTableEntry * extEntry;
    struct List * baserestrictinfo;
    struct QualCost baserestrictcost;
    struct List * joininfo;
    bool has_eclass_joins;
    undefined field_0x111;
    undefined field_0x112;
    undefined field_0x113;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    struct ForeignTable * ftEntry;
};

struct CdbCopy { /* DWARF DIE: 20ca29 */
    int total_segs;
    bool copy_in;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct StringInfoData copy_out_buf;
    struct List * seglist;
    struct HTAB * aotupcounts;
    struct CdbDispatcherState * dispatcherState;
};

struct ResultRelInfo { /* DWARF DIE: df57 */
    enum NodeTag type;
    Index ri_RangeTableIndex;
    Relation ri_RelationDesc;
    int ri_NumIndices;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    RelationPtr ri_IndexRelationDescs;
    struct IndexInfo * * ri_IndexRelationInfo;
    struct TriggerDesc * ri_TrigDesc;
    struct FmgrInfo * ri_TrigFunctions;
    struct List * * ri_TrigWhenExprs;
    struct Instrumentation * ri_TrigInstrument;
    struct FdwRoutine * ri_FdwRoutine;
    void * ri_FdwState;
    struct List * ri_WithCheckOptions;
    struct List * ri_WithCheckOptionExprs;
    struct List * * ri_ConstraintExprs;
    struct JunkFilter * ri_junkFilter;
    AttrNumber ri_segid_attno;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    struct ProjectionInfo * ri_projectReturning;
    int tupdesc_match;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    struct MemTupleBinding * mt_bind;
    struct AppendOnlyInsertDescData * ri_aoInsertDesc;
    struct AOCSInsertDescData * ri_aocsInsertDesc;
    struct ExternalInsertDescData * ri_extInsertDesc;
    RelationDeleteDesc ri_deleteDesc;
    RelationUpdateDesc ri_updateDesc;
    int ri_aosegno;
    undefined field_0xc4;
    undefined field_0xc5;
    undefined field_0xc6;
    undefined field_0xc7;
    uint64 ri_aoprocessed;
    struct AttrMap * ri_partInsertMap;
    struct TupleTableSlot * ri_resultSlot;
    Relation ri_PartitionParent;
    int ri_PartCheckTupDescMatch;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    struct AttrMap * ri_PartCheckMap;
    struct HTAB * ri_partition_hash;
    BulkInsertState biState;
    int nBufferedTuples;
    undefined field_0x10c;
    undefined field_0x10d;
    undefined field_0x10e;
    undefined field_0x10f;
    HeapTuple * bufferedTuples;
    Size bufferedTuplesSize;
};

struct SnapshotData { /* DWARF DIE: bacc */
    bool (* satisfies)(Relation, HeapTuple, Snapshot, Buffer);
    TransactionId xmin;
    TransactionId xmax;
    TransactionId * xip;
    uint32 xcnt;
    int32 subxcnt;
    TransactionId * subxip;
    bool suboverflowed;
    bool takenDuringRecovery;
    bool copied;
    bool haveDistribSnapshot;
    CommandId curcid;
    uint32 active_count;
    uint32 regd_count;
    struct DistributedSnapshotWithLocalMapping distribSnapshotWithLocalMapping;
};

struct DatumStreamWrite { /* DWARF DIE: 2bcb91 */
    struct DatumStreamTypeInfo typeInfo;
    enum DatumStreamVersion datumStreamVersion;
    bool rle_want_compression;
    bool delta_want_compression;
    undefined field_0x12;
    undefined field_0x13;
    int32 maxAoBlockSize;
    int32 maxAoHeaderSize;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    char * title;
    bool need_close_file;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    struct AppendOnlyStorageAttributes ao_attr;
    struct AppendOnlyStorageWrite ao_write;
    int64 blockFirstRowNum;
    struct DatumStreamBlockWrite blockWrite;
    int64 eof;
    int64 eofUncompress;
};

struct pg_conn { /* DWARF DIE: 4d7254 */
    char * pghost;
    char * pghostaddr;
    char * pgport;
    char * pgunixsocket;
    char * pgtty;
    char * connect_timeout;
    char * client_encoding_initial;
    char * pgoptions;
    char * appname;
    char * fbappname;
    char * dbName;
    char * replication;
    char * pguser;
    char * pgpass;
    char * keepalives;
    char * keepalives_idle;
    char * keepalives_interval;
    char * keepalives_count;
    char * sslmode;
    char * sslcompression;
    char * sslkey;
    char * sslcert;
    char * sslrootcert;
    char * sslcrl;
    char * requirepeer;
    char * gpconntype;
    char * gpqeid;
    FILE * Pfdebug;
    struct PGNoticeHooks noticeHooks;
    struct PGEvent * events;
    int nEvents;
    int eventArraySize;
    enum ConnStatusType status;
    enum PGAsyncStatusType asyncStatus;
    enum PGTransactionStatusType xactStatus;
    enum PGQueryClass queryclass;
    char * last_query;
    char last_sqlstate[6];
    bool options_valid;
    bool nonblocking;
    bool singleRowMode;
    char copy_is_binary;
    undefined field_0x132;
    undefined field_0x133;
    int copy_already_done;
    PGnotify * notifyHead;
    PGnotify * notifyTail;
    pgsocket sock;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    struct SockAddr laddr;
    struct SockAddr raddr;
    ProtocolVersion pversion;
    int sversion;
    bool auth_req_received;
    bool password_needed;
    bool dot_pgpass_used;
    bool sigpipe_so;
    bool sigpipe_flag;
    bool try_next_addr;
    bool is_new_addr;
    undefined field_0x26f;
    struct addrinfo * addrlist;
    struct addrinfo * addr_cur;
    int addrlist_family;
    enum PGSetenvStatusType setenv_state;
    struct PQEnvironmentOption * next_eo;
    bool send_appname;
    undefined field_0x291;
    undefined field_0x292;
    undefined field_0x293;
    int be_pid;
    int be_key;
    undefined field_0x29c;
    undefined field_0x29d;
    undefined field_0x29e;
    undefined field_0x29f;
    int64 mop_high_watermark;
    char md5Salt[4];
    undefined field_0x2ac;
    undefined field_0x2ad;
    undefined field_0x2ae;
    undefined field_0x2af;
    struct pgParameterStatus * pstatus;
    int client_encoding;
    bool std_strings;
    undefined field_0x2bd;
    undefined field_0x2be;
    undefined field_0x2bf;
    enum PGVerbosity verbosity;
    undefined field_0x2c4;
    undefined field_0x2c5;
    undefined field_0x2c6;
    undefined field_0x2c7;
    PGlobjfuncs * lobjfuncs;
    char * inBuffer;
    int inBufSize;
    int inStart;
    int inCursor;
    int inEnd;
    char * outBuffer;
    int outBufSize;
    int outCount;
    bool outBuffer_shared;
    undefined field_0x2f9;
    undefined field_0x2fa;
    undefined field_0x2fb;
    undefined field_0x2fc;
    undefined field_0x2fd;
    undefined field_0x2fe;
    undefined field_0x2ff;
    char * outBufferSaved;
    int outMsgStart;
    int outMsgEnd;
    PGdataValue * rowBuf;
    int rowBufLen;
    undefined field_0x31c;
    undefined field_0x31d;
    undefined field_0x31e;
    undefined field_0x31f;
    PGresult * result;
    PGresult * next_result;
    char wrote_xlog;
    undefined field_0x331;
    undefined field_0x332;
    undefined field_0x333;
    undefined field_0x334;
    undefined field_0x335;
    undefined field_0x336;
    undefined field_0x337;
    struct PQExpBufferData errorMessage;
    struct PQExpBufferData workBuffer;
};

struct Trigger { /* DWARF DIE: b675 */
    Oid tgoid;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * tgname;
    Oid tgfoid;
    int16 tgtype;
    char tgenabled;
    bool tgisinternal;
    Oid tgconstrrelid;
    Oid tgconstrindid;
    Oid tgconstraint;
    bool tgdeferrable;
    bool tginitdeferred;
    int16 tgnargs;
    int16 tgnattr;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    int16 * tgattr;
    char * * tgargs;
    char * tgqual;
};

struct attrDefault { /* DWARF DIE: 1dac */
    AttrNumber adnum;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * adbin;
};

struct ParamListInfoData { /* DWARF DIE: bc15 */
    void (* paramFetch)(ParamListInfo, int);
    void * paramFetchArg;
    void (* parserSetup)(struct ParseState *, void *);
    void * parserSetupArg;
    int numParams;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    struct ParamExternData params[1];
};

struct PartitionState { /* DWARF DIE: e1fa */
    enum NodeTag type;
    AttrNumber max_partition_attr;
    undefined field_0x6;
    undefined field_0x7;
    struct PartitionAccessMethods * accessMethods;
};

struct PlannedStmt { /* DWARF DIE: cb47 */
    enum NodeTag type;
    enum CmdType commandType;
    enum PlanGenerator planGen;
    uint32 queryId;
    bool hasReturning;
    bool hasModifyingCTE;
    bool canSetTag;
    bool transientPlan;
    bool oneoffPlan;
    bool simplyUpdatable;
    undefined field_0x16;
    undefined field_0x17;
    struct Plan * planTree;
    struct List * rtable;
    struct List * resultRelations;
    struct Node * utilityStmt;
    struct List * subplans;
    struct Bitmapset * rewindPlanIDs;
    struct PartitionNode * result_partitions;
    struct List * result_aosegnos;
    struct List * queryPartOids;
    struct List * queryPartsMetadata;
    struct List * numSelectorsPerScanId;
    struct List * rowMarks;
    struct List * relationOids;
    struct List * invalItems;
    int nParamExec;
    int nMotionNodes;
    int nInitPlans;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    struct GpPolicy * intoPolicy;
    uint64 query_mem;
    struct IntoClause * intoClause;
    struct CopyIntoClause * copyIntoClause;
    int8 metricsQueryType;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
};

struct ExplainState { /* DWARF DIE: 4f088e */
    StringInfo str;
    bool verbose;
    bool analyze;
    bool costs;
    bool buffers;
    bool dxl;
    bool timing;
    bool summary;
    undefined field_0xf;
    enum ExplainFormat format;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    struct PlannedStmt * pstmt;
    struct List * rtable;
    struct List * rtable_names;
    int indent;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    struct ExplainStateExtra * extra;
    struct CdbExplain_ShowStatCtx * showstatctx;
    struct Slice * currentSlice;
    struct PlanState * parentPlanState;
};

struct ExternalInsertDescData { /* DWARF DIE: 20b686 */
    Relation ext_rel;
    struct URL_FILE * ext_file;
    char * ext_uri;
    bool ext_noop;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    TupleDesc ext_tupDesc;
    Datum * ext_values;
    bool * ext_nulls;
    struct FmgrInfo * ext_custom_formatter_func;
    struct List * ext_custom_formatter_params;
    struct FormatterData * ext_formatter_data;
    struct CopyStateData * ext_pstate;
};

struct GpSegConfigEntry { /* DWARF DIE: 20c8e4 */
    int16 dbid;
    int16 segindex;
    char role;
    char preferred_role;
    char mode;
    char status;
    int32 port;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    char * hostname;
    char * address;
    char * datadir;
    char * hostip;
    char * hostaddrs[8];
};

struct Slice { /* DWARF DIE: 4f0500 */
    enum NodeTag type;
    int sliceIndex;
    int rootIndex;
    int parentIndex;
    struct List * children;
    enum GangType gangType;
    int gangSize;
    struct DirectDispatchInfo directDispatch;
    struct Gang * primaryGang;
    struct List * primaryProcesses;
    struct Bitmapset * processesMap;
    struct List * segments;
};

struct pgMessageField { /* DWARF DIE: 4d7bbc */
    struct pgMessageField * next;
    char code;
    char contents[1];
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct FormData_pg_am { /* DWARF DIE: b134 */
    NameData amname;
    int16 amstrategies;
    int16 amsupport;
    bool amcanorder;
    bool amcanorderbyop;
    bool amcanbackward;
    bool amcanunique;
    bool amcanmulticol;
    bool amoptionalkey;
    bool amsearcharray;
    bool amsearchnulls;
    bool amstorage;
    bool amclusterable;
    bool ampredlocks;
    undefined field_0x4f;
    Oid amkeytype;
    regproc aminsert;
    regproc ambeginscan;
    regproc amgettuple;
    regproc amgetbitmap;
    regproc amrescan;
    regproc amendscan;
    regproc ammarkpos;
    regproc amrestrpos;
    regproc ambuild;
    regproc ambuildempty;
    regproc ambulkdelete;
    regproc amvacuumcleanup;
    regproc amcanreturn;
    regproc amcostestimate;
    regproc amoptions;
};

struct TupleChunkListItemData { /* DWARF DIE: 598396 */
    struct TupleChunkListItemData * p_next;
    uint32 chunk_length;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    char * inplace;
    uint8 chunk_data[0];
};

struct CdbProcess { /* DWARF DIE: 598890 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * listenerAddr;
    int listenerPort;
    int pid;
    int contentid;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
};

struct CdbExplain_StatInst { /* DWARF DIE: 525ba8 */
    enum NodeTag pstype;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    instr_time starttime;
    instr_time counter;
    double firsttuple;
    double startup;
    double total;
    double ntuples;
    double nloops;
    double execmemused;
    double workmemused;
    double workmemwanted;
    bool workfileCreated;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    instr_time firststart;
    double peakMemBalance;
    int numPartScanned;
    enum ExplainSortMethod sortMethod;
    enum ExplainSortSpaceType sortSpaceType;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    long sortSpaceUsed;
    int bnotes;
    int enotes;
};

struct pgresAttDesc { /* DWARF DIE: 4d793e */
    char * name;
    Oid tableid;
    int columnid;
    int format;
    Oid typid;
    int typlen;
    int atttypmod;
};

struct ExtTableEntry { /* DWARF DIE: 20ce5f */
    struct List * urilocations;
    struct List * execlocations;
    char fmtcode;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    char * fmtopts;
    struct List * options;
    char * command;
    int rejectlimit;
    char rejectlimittype;
    bool logerrors;
    undefined field_0x36;
    undefined field_0x37;
    int encoding;
    bool iswritable;
    bool isweb;
    undefined field_0x3e;
    undefined field_0x3f;
};

struct EState { /* DWARF DIE: dafc */
    enum NodeTag type;
    enum ScanDirection es_direction;
    Snapshot es_snapshot;
    Snapshot es_crosscheck_snapshot;
    struct List * es_range_table;
    struct PlannedStmt * es_plannedstmt;
    struct JunkFilter * es_junkFilter;
    CommandId es_output_cid;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    struct ResultRelInfo * es_result_relations;
    int es_num_result_relations;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    struct ResultRelInfo * es_result_relation_info;
    struct List * es_trig_target_relations;
    struct PartitionNode * es_result_partitions;
    struct List * es_result_aosegnos;
    struct TupleTableSlot * es_trig_tuple_slot;
    struct TupleTableSlot * es_trig_oldtup_slot;
    struct TupleTableSlot * es_trig_newtup_slot;
    ParamListInfo es_param_list_info;
    struct ParamExecData * es_param_exec_vals;
    MemoryContext es_query_cxt;
    struct List * es_tupleTable;
    struct List * es_rowMarks;
    uint64 es_processed;
    Oid es_lastoid;
    int es_top_eflags;
    int es_instrument;
    bool es_finished;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    struct List * es_exprcontexts;
    struct List * es_subplanstates;
    struct List * es_auxmodifytables;
    struct ExprContext * es_per_tuple_exprcontext;
    HeapTuple * es_epqTuple;
    bool * es_epqTupleSet;
    bool * es_epqScanDone;
    struct SliceTable * es_sliceTable;
    struct List * es_cursorPositions;
    struct List * * es_sharenode;
    int active_recv_id;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    void * motionlayer_context;
    struct ChunkTransportState * interconnect_context;
    bool es_interconnect_is_setup;
    bool es_got_eos;
    bool cancelUnfinished;
    undefined field_0x12b;
    undefined field_0x12c;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined field_0x12f;
    struct CdbDispatcherState * dispatcherState;
    struct CdbExplain_ShowStatCtx * showstatctx;
    struct PartitionState * es_partition_state;
    int currentSliceIdInPlan;
    int currentExecutingSliceId;
    int currentSubplanLevel;
    int rootSliceId;
    struct DynamicTableScanInfo * dynamicTableScanInfo;
    bool eliminateAliens;
    undefined field_0x161;
    undefined field_0x162;
    undefined field_0x163;
    undefined field_0x164;
    undefined field_0x165;
    undefined field_0x166;
    undefined field_0x167;
};

struct _IO_marker { /* DWARF DIE: 263 */
    struct _IO_marker * _next;
    struct _IO_FILE * _sbuf;
    int _pos;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct IndexInfo { /* DWARF DIE: d8e2 */
    enum NodeTag type;
    int ii_NumIndexAttrs;
    AttrNumber ii_KeyAttrNumbers[32];
    struct List * ii_Expressions;
    struct List * ii_ExpressionsState;
    struct List * ii_Predicate;
    struct List * ii_PredicateState;
    Oid * ii_ExclusionOps;
    Oid * ii_ExclusionProcs;
    uint16 * ii_ExclusionStrats;
    bool ii_Unique;
    bool ii_ReadyForInserts;
    bool ii_Concurrent;
    bool ii_BrokenHotChain;
    Oid ii_Am;
};

struct MemoryContextData { /* DWARF DIE: 86f5 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct MemoryContextMethods methods;
    MemoryContext parent;
    MemoryContext firstchild;
    MemoryContext nextchild;
    char * name;
    bool isReset;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    uint64 allBytesAlloc;
    uint64 allBytesFreed;
    Size maxBytesHeld;
    Size localMinHeld;
};

struct CdbExplain_NodeSummary { /* DWARF DIE: 51f226 */
    struct CdbExplain_Agg ntuples;
    struct CdbExplain_Agg execmemused;
    struct CdbExplain_Agg workmemused;
    struct CdbExplain_Agg workmemwanted;
    struct CdbExplain_Agg totalWorkfileCreated;
    struct CdbExplain_Agg peakMemBalance;
    struct CdbExplain_Agg totalPartTableScanned;
    struct CdbExplain_Agg sortSpaceUsed[2][5];
    int segindex0;
    int ninst;
    struct CdbExplain_StatInst insts[1];
};

struct MinipagePerColumnGroup { /* DWARF DIE: 1146f1 */
    struct Minipage * minipage;
    uint32 numMinipageEntries;
    struct ItemPointerData tupleTid;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct _IO_FILE { /* DWARF DIE: dc */
    int _flags;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * _IO_read_ptr;
    char * _IO_read_end;
    char * _IO_read_base;
    char * _IO_write_base;
    char * _IO_write_ptr;
    char * _IO_write_end;
    char * _IO_buf_base;
    char * _IO_buf_end;
    char * _IO_save_base;
    char * _IO_backup_base;
    char * _IO_save_end;
    struct _IO_marker * _markers;
    struct _IO_FILE * _chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    _IO_lock_t * _lock;
    __off64_t _offset;
    void * __pad1;
    void * __pad2;
    void * __pad3;
    void * __pad4;
    size_t __pad5;
    int _mode;
    char _unused2[20];
};

struct tupleDesc { /* DWARF DIE: 1e84 */
    int natts;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    Form_pg_attribute * attrs;
    TupleConstr * constr;
    Oid tdtypeid;
    int32 tdtypmod;
    bool tdhasoid;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    int tdrefcount;
};

struct CopyStateData { /* DWARF DIE: 20c367 */
    enum CopyDest copy_dest;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    FILE * copy_file;
    StringInfo fe_msgbuf;
    bool fe_eof;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    enum EolType eol_type;
    char * eol_str;
    int file_encoding;
    bool need_transcoding;
    bool encoding_embeds_ascii;
    undefined field_0x2e;
    undefined field_0x2f;
    struct FmgrInfo * enc_conversion_proc;
    Relation rel;
    struct QueryDesc * queryDesc;
    struct List * attnumlist;
    struct List * attnamelist;
    char * filename;
    bool is_program;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    int (* data_source_cb)(void *, int, void *);
    void * data_source_cb_extra;
    bool oids;
    bool freeze;
    bool binary;
    bool csv_mode;
    bool header_line;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    char * null_print;
    int null_print_len;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    char * null_print_client;
    char * delim;
    char * quote;
    char * escape;
    struct List * force_quote;
    bool force_quote_all;
    undefined field_0xb9;
    undefined field_0xba;
    undefined field_0xbb;
    undefined field_0xbc;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    bool * force_quote_flags;
    struct List * force_notnull;
    bool * force_notnull_flags;
    struct List * force_null;
    bool * force_null_flags;
    bool convert_selectively;
    undefined field_0xe9;
    undefined field_0xea;
    undefined field_0xeb;
    undefined field_0xec;
    undefined field_0xed;
    undefined field_0xee;
    undefined field_0xef;
    struct List * convert_select;
    bool * convert_select_flags;
    bool fill_missing;
    undefined field_0x101;
    undefined field_0x102;
    undefined field_0x103;
    undefined field_0x104;
    undefined field_0x105;
    undefined field_0x106;
    undefined field_0x107;
    struct SingleRowErrorDesc * sreh;
    char * cur_relname;
    int64 cur_lineno;
    char * cur_attname;
    char * cur_attval;
    enum CopyDispatchMode dispatch_mode;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    MemoryContext copycontext;
    struct FmgrInfo * out_functions;
    MemoryContext rowcontext;
    AttrNumber num_defaults;
    bool file_has_oids;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    struct FmgrInfo oid_in_function;
    Oid oid_typioparam;
    undefined field_0x18c;
    undefined field_0x18d;
    undefined field_0x18e;
    undefined field_0x18f;
    struct FmgrInfo * in_functions;
    Oid * typioparams;
    int * defmap;
    struct ExprState * * defexprs;
    bool volatile_defexprs;
    undefined field_0x1b1;
    undefined field_0x1b2;
    undefined field_0x1b3;
    undefined field_0x1b4;
    undefined field_0x1b5;
    undefined field_0x1b6;
    undefined field_0x1b7;
    struct List * range_table;
    StringInfo dispatch_msgbuf;
    enum CopyErrMode errMode;
    undefined field_0x1cc;
    undefined field_0x1cd;
    undefined field_0x1ce;
    undefined field_0x1cf;
    struct CdbSreh * cdbsreh;
    int lastsegid;
    undefined field_0x1dc;
    undefined field_0x1dd;
    undefined field_0x1de;
    undefined field_0x1df;
    struct StringInfoData attribute_buf;
    int max_fields;
    undefined field_0x1fc;
    undefined field_0x1fd;
    undefined field_0x1fe;
    undefined field_0x1ff;
    char * * raw_fields;
    struct StringInfoData line_buf;
    bool line_buf_converted;
    bool line_buf_valid;
    undefined field_0x222;
    undefined field_0x223;
    undefined field_0x224;
    undefined field_0x225;
    undefined field_0x226;
    undefined field_0x227;
    char * raw_buf;
    int raw_buf_index;
    int raw_buf_len;
    bool escape_off;
    undefined field_0x239;
    undefined field_0x23a;
    undefined field_0x23b;
    undefined field_0x23c;
    undefined field_0x23d;
    undefined field_0x23e;
    undefined field_0x23f;
    struct PartitionNode * partitions;
    struct List * ao_segnos;
    bool skip_ext_partition;
    bool on_segment;
    bool ignore_extra_line;
    undefined field_0x253;
    undefined field_0x254;
    undefined field_0x255;
    undefined field_0x256;
    undefined field_0x257;
    struct ProgramPipes * program_pipes;
    struct CdbCopy * cdbCopy;
};

struct ExprContext { /* DWARF DIE: da0b */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct TupleTableSlot * ecxt_scantuple;
    struct TupleTableSlot * ecxt_innertuple;
    struct TupleTableSlot * ecxt_outertuple;
    MemoryContext ecxt_per_query_memory;
    MemoryContext ecxt_per_tuple_memory;
    struct ParamExecData * ecxt_param_exec_vals;
    ParamListInfo ecxt_param_list_info;
    Datum * ecxt_aggvalues;
    bool * ecxt_aggnulls;
    Datum caseValue_datum;
    bool caseValue_isNull;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    Datum domainValue_datum;
    bool domainValue_isNull;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    struct EState * ecxt_estate;
    struct ExprContext_CB * ecxt_callbacks;
    uint64 grouping;
    uint32 group_id;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
};

struct ForeignPath { /* DWARF DIE: 49cde5 */
    struct Path path;
    struct List * fdw_private;
};

struct FormData_pg_index { /* DWARF DIE: b502 */
    Oid indexrelid;
    Oid indrelid;
    int16 indnatts;
    bool indisunique;
    bool indisprimary;
    bool indisexclusion;
    bool indimmediate;
    bool indisclustered;
    bool indisvalid;
    bool indcheckxmin;
    bool indisready;
    bool indislive;
    bool indisreplident;
    struct int2vector indkey;
};

struct MotionConn { /* DWARF DIE: 59840e */
    int sockfd;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct ICBufferList sndQueue;
    int capacity;
    uint32 sentSeq;
    uint32 receivedAckSeq;
    uint32 consumedSeq;
    uint64 rtt;
    uint64 dev;
    uint64 deadlockCheckBeginTime;
    struct ICBuffer * curBuff;
    struct ICBufferList unackQueue;
    uint8 * pBuff;
    uint16 route;
    undefined field_0x72;
    undefined field_0x73;
    int32 msgSize;
    uint8 * msgPos;
    int32 recvBytes;
    int tupleCount;
    bool stillActive;
    bool stopRequested;
    undefined field_0x8a;
    undefined field_0x8b;
    enum MotionConnState state;
    uint64 wakeup_ms;
    struct icpkthdr conn_info;
    struct CdbProcess * cdbProc;
    int remoteContentId;
#if 0
    char remoteHostAndPort[128];
    char localHostAndPort[128];
    undefined field_0x1e4;
    undefined field_0x1e5;
    undefined field_0x1e6;
    undefined field_0x1e7;
    struct sockaddr_storage peer;
    socklen_t peer_len;
    int pkt_q_capacity;
    int pkt_q_size;
    int pkt_q_head;
    int pkt_q_tail;
    undefined field_0x27c;
    undefined field_0x27d;
    undefined field_0x27e;
    undefined field_0x27f;
    uint8 * * pkt_q;
    uint64 stat_total_ack_time;
    uint64 stat_count_acks;
    uint64 stat_max_ack_time;
    uint64 stat_min_ack_time;
    uint64 stat_count_resent;
    uint64 stat_max_resent;
    uint64 stat_count_dropped;
    int32 sent_record_typmod;
    undefined field_0x2c4;
    undefined field_0x2c5;
    undefined field_0x2c6;
    undefined field_0x2c7;
    struct TupleRemapper * remapper;
#endif
};

struct SingleRowErrorDesc { /* DWARF DIE: 2071f1 */
    enum NodeTag type;
    int rejectlimit;
    bool is_limit_in_rows;
    bool into_file;
    undefined field_0xa;
    undefined field_0xb;
};

union pgresult_data { /* DWARF DIE: 4d7b3f */
    PGresult_data * next;
    char space[1];
};

struct QueryDispatchDesc { /* DWARF DIE: e5b9 */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * intoTableSpaceName;
    struct List * oidAssignments;
    struct SliceTable * sliceTable;
    struct List * cursorPositions;
    bool useChangedAOOpts;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
};

struct Alias { /* DWARF DIE: befc */
    enum NodeTag type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * aliasname;
    struct List * colnames;
};

struct CdbDispatchResults_SliceInfo { /* DWARF DIE: 285208 */
    int resultBegin;
    int resultEnd;
};

struct RelationData { /* DWARF DIE: a7bc */
    struct RelFileNode rd_node;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct SMgrRelationData * rd_smgr;
    int rd_refcnt;
    BackendId rd_backend;
    bool rd_islocaltemp;
    bool rd_isnailed;
    bool rd_isvalid;
    char rd_indexvalid;
    SubTransactionId rd_createSubid;
    SubTransactionId rd_newRelfilenodeSubid;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    Form_pg_class rd_rel;
    TupleDesc rd_att;
    Oid rd_id;
    struct LockInfoData rd_lockInfo;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    struct RuleLock * rd_rules;
    MemoryContext rd_rulescxt;
    struct TriggerDesc * trigdesc;
    struct GpPolicy * rd_cdbpolicy;
    bool rd_cdbDefaultStatsWarningIssued;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    struct List * rd_indexlist;
    Oid rd_oidindex;
    Oid rd_replidindex;
    struct Bitmapset * rd_indexattr;
    struct Bitmapset * rd_keyattr;
    struct Bitmapset * rd_idattr;
    bytea * rd_options;
    Form_pg_index rd_index;
    struct HeapTupleData * rd_indextuple;
    Form_pg_am rd_am;
    MemoryContext rd_indexcxt;
    struct RelationAmInfo * rd_aminfo;
    Oid * rd_opfamily;
    Oid * rd_opcintype;
    RegProcedure * rd_support;
    struct FmgrInfo * rd_supportinfo;
    int16 * rd_indoption;
    struct List * rd_indexprs;
    struct List * rd_indpred;
    Oid * rd_exclops;
    Oid * rd_exclprocs;
    uint16 * rd_exclstrats;
    void * rd_amcache;
    Oid * rd_indcollation;
    struct FdwRoutine * rd_fdwroutine;
    Oid rd_toastoid;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    Form_pg_appendonly rd_appendonly;
    struct HeapTupleData * rd_aotuple;
    struct PgStat_TableStatus * pgstat_info;
};

struct PGEvent { /* DWARF DIE: 4d7c42 */
    int (* proc)(enum PGEventId, void *, void *);
    char * name;
    void * passThrough;
    void * data;
    bool resultInitialized;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
};

