unit PrjConst;

interface

uses SysUtils
  ;

resourcestring
  SVersion = 'Version ';
  SDatabase = 'Database ';

  //uMain
  sh0070 = 'Version';
  sh0080 = 'Ver';


function GetTranslatedText(nameOfConstant : String) : String;
procedure GenerateTranslateTextTableForConstants;
procedure GenerateTranslateTextTableForAllForms;


implementation

uses uAppGlobal,
  uProvideARoom2,

  uRoomerLanguage,
//  uInvoiceInfo,
  uInvoice,
  uReservationProfile,
  uInvoicePayment,
  uControlData,
  uFinishedInvoices2,
//  uRoomStatus,
  uCreditPrompt,
//  uInvoiceCompress,
  uInvoiceList,
  uConverts,
  ufrmSelLang,
//  uHotelListMissing,
  uMaidActions,
  uMaidActionsEdit,
  uInvoiceSummeryOBJ,
//  uMakeReservation,
  uRoomDateProblem,
  uResProblem,
//  uStatisticsForcast,
  uDayFinical,
  uConvertGroups,
  uInvoiceList2,
//  uRptCustomer,
  uDayNotes,
  uChangeRRdates,
  uChangeRate,
  uOpenInvoicesNew,
  uResMemos,
  uHomeDate,
  uAllotmentToRes,
  uGoToRoomAndDate,
  uHiddenInfo,
  uDownPayment,
  uFrmChannelTogglingRules,
  uLodgingTaxReport2,
  uCancelReservation3,
  uCancelReservation2,
  uNationalReport3,
  uAddAccommodation,
  uCountries,
  uPayGroups,
  uPriceCodes,
  uGuestProfile2,
  uPayTypes,
  uCountryGroups,
  uVatCodes,
  uRebuildReservationStats,
  uMakeReservationQuick,
  uSplashRoomer,
  RoomerLoginForm,
  uAboutRoomer,
  uManageFilesOnServer,
  uChannelAvailabilityManager,
  ueditRoomPrice,
  uRoomCleanMaintenanceStatus,
  uRates,
  uSeasons2,
  uRoomRates,
  uRoomTypesGroups2,
  uRoomTypes2,
  uPackageItems,
  uRooms3,
  uCustomers2,
  uStaffEdit2,
  uStaffMembers2,
  uCustomerEdit2,
  uChannels,
//  uSystemTriggers,
//  uCreatePassword,
//  uSystemServers,
//  uSystemActions,
//  uChannelRates,
  uStaffTypes2,
  uItems2,
  uItemTypes2,
  uLocations2,
  uCurrencies,
  uChannelManager,
  uCommunicationTest,
  uHouseKeeping,
//  uTableEditForm,
  uRptResStats,
  uGuestSearch,
//  uRptResDates,
  uMultiSelection,
  uPersonviptypes,
  uPersoncontacttype,
  ufrmKeyPairSelector,
  uFrmResources,
  uAssignPayment,
  ufDownPayments,
  uTaxes,
  uFrmMessagesTemplates,
  uFrmNotepad,
  uRptResInvoices,
  uRptTotallist,
  uRptCustInvoices,
  uFrmRBEContainer,
  uFrmRbePreferences,
  urptManagment,
  uFrmHandleBookKeepingException,
  uRoomClassEdit,
  urptReservations,
  uFrmPostInvoices,
  urptBreakfastGuests,
  uGuestCheckInForm,
  uRptNotes,
//  uRptGuests,

  uReservationHintHolder,
  uEmbOccupancyView,
  uembPeriodView,
  uFrmRateQuery,

  uRptTurnoverAndPayments,
  uRptResStatsRooms,

  uRptReservationsCust,

  uEmailingDialog,
  uMakeKreditInvoice,

  uGuestProfiles,
  uGuestPortfolioEdit,

  uBookKeepingCodes,

  uFrmEditEmailProperties,

  uRptBookkeeping,
  uReservationEmailingDialog,
  uFrmReservationCancellationDialog,

  uRptCashier,

  uPhoneRates,
  uGroupGuests,

  uEmailExcelSheet,
//  uInvoice2015,
  uInvoiceLineEdit,
  uFrmMergePortfolios,
  uStaffComm,
  uFrmCheckOut,
  uFrmStaffNote,
  uFrmMessageViewer,
  uInvoiceCompare,
  uFrmAlertEdit,
  uFrmAlertDialog,
  uAlertEditPanel,
  uFrmCustomerDepartmentEdit

  , uOfflineReportGrid
  , uHotelStatusOfflineReport
  , uHotelArrivalsOfflineReport
  , uRptArrivals
  , uFrmRoomReservationCancellationDialog;


const PRE_KEY_NAME = 'PrjConst.Constants.';


procedure OriginalConstants;
begin
  with ConstantsDictionary do
  begin
    Add('SVersion', 'Version ');
    Add('sDatabase', 'Database ');

    //uMain
    Add('sh0070', 'Version');
    Add('sh0080', 'Ver');
    Add('shWrongLoginAttempts', 'Wrong username or password - %d attempts.');
    Add('shStillWorkingInInvoice',
                      'You still are working on an invoice!' + #13#13 +
                      'Please finish working on the current invoice before proceeding.');
    Add('sh1004', 'Quit ROOMER?');
    Add('sh1007', 'Can not access from Guest view');
    Add('sh1008', 'Can not access from period view');
    Add('sh1010', 'Room status is Checked-in');
    Add('shCheckInGroupOfRoom', 'Check in the group that this room [%s] belongs to?');
    Add('sh1013', 'Room status is blocked and check in or check out is not possible');
    Add('sh1014', 'Room status is checked-out');
    Add('sh1015', 'Room status is reserved (not checked-in)');
    Add('sh1016', 'Room status is overbooked');
    Add('sh1017', 'Room status is reserved');
    Add('sh1018', 'Room status is allotment');
    Add('sh1019', 'Room status is no-show');
    Add('sh1020', 'Room status is Chanceled');
    Add('sh1021', 'Room status is Tmp1');
    Add('sh1022', 'Room status is Tmp2');
    Add('shCheckOutSelectedRoom', 'Check-out room %s?');
    Add('shCannotCheckoutRoom', '%s - Can not check-out room %s.');
    Add('shStatusIsNoShowFirstChange', 'Status is NO-show.' + #13#13 + 'You need to change the status first.');
    Add('sh1080', 'error - rooms Grid');
    Add('sh1081', 'error - no-Rooms-grid');

    Add('sh1091', 'error raised, with message');
    Add('sh1092a', 'The program to execute');

    Add('sh1092b', 'not found');
    Add('sh1045', 'Invoice: <b>Not made or unknown</b>.');
    Add('sh1046', 'Invoice: <b>Compressed lines - Unknown</b>.');
    Add('shOneDayGetReservationRoom', '%s / Reservation: %s (%d rooms) / %s');
    Add('shRooms', 'Rooms');
    Add('shMainFormStatisticsRooms', 'Rooms');
    Add('shRoom', 'Room');
    Add('shCheckRoom', 'Check in room %s');
    Add('shType', 'Type');
    Add('shGuestReservation', 'Guest/reservation');
    Add('shArrival', 'Arrival');
    Add('shDeparture', 'Departure');
    Add('shRoomInformation', 'Room information');
    Add('shBookingIdText', 'Channel Booking Id');
    Add('shRoomNotAssignedYet', 'This reservation has not been assigned a room yet');
    Add('shWAITINGLIST', 'WAITINGLIST');
    //Add('shALOTMENT', 'ALOTMENT');
    Add('shALOTMENT', 'ALLOTMENT');
    Add('shNOSHOW', 'NO-SHOW');
    Add('shBLOCKED', 'BLOCKED');

    Add('shCanceled', 'CANCELED'); //*HJ 140206
    Add('shTMP1', 'TMP1'); //*HJ 140206
    Add('shTMP2', 'TMP2'); //*HJ 140206

    Add('shTelephone', 'Telephone');
    Add('shFax', 'Fax');
    Add('shPrice', 'Price');
    Add('shPriceAfterDiscount', 'Price after discount');
    Add('shDiscount', 'Discount');
    Add('shInvoice', 'Invoice');
    Add('shRoomMemo', 'Room Memo');
    Add('shPaymentInfo', 'Payment info');
  //  Add('shRefrence', 'Refrence');
    Add('shRefrence', 'Reference');
    Add('shReserved', 'Reserved : ');
    Add('shResMemo', 'Res Memo');
    Add('shToOneDay', 'To one day');
    Add('shHideText', 'Hide text');
    Add('shShowText', 'Show text');
    Add('shCreated', 'Created');
    Add('shUser', 'User');
    Add('shGroups', 'Groups');
    Add('shArriving', 'Arriving');
    Add('shDeparting', 'Departing');
    Add('shPasswordNoMatch', 'Passwords Don''t match');
    Add('shAll', 'All');
    //Login
    Add('shDaysLeft', 'Days left');
    // TfrmMakeReservationQuick
    Add('shNotF_star', '** not found **');
    Add('shNotF_upph', ' not found !!');
    Add('shPriceFor', 'price for ');
    Add('shAndCurrency', 'and Currency ');
    Add('shAndPersonVipType', 'and Person VIP Type ');
    Add('shAndPersonContactType', 'and Person Contact Type ');
    // uCountryGroups;
    Add('shDeleteCountrygroup', 'Delete countrygroup');
    Add('shDeleteChannelManager', 'Delete channel manager');
    Add('shDeleteConvertItem', 'Delete convert item');
    Add('shDeleteCountry', 'Delete country');
    Add('shDeleteCurrency', 'Delete currency');
    Add('shDeletePersonVipType', 'Delete Person VIP Type');
    Add('shDeletePersonContactType', 'Delete Person Contact Type');

    Add('shDeletePhoneRate', 'Delete Phone rate');
    Add('shDeletepaygroup', 'Delete paygroup');
    Add('shDeletepayType', 'Delete paytype');
    Add('shDeleteRateRule', 'Delete Rate rule');
    Add('shDeleteRoomRate', 'Delete Room rate');
    Add('shDeleteRoomClass', 'Delete Room class');
    Add('shDeleteSeason', 'Delete season');
    Add('shDeleteItemtype', 'Delete item type');
    Add('shDeleteItem', 'Delete item');
    Add('shDeleteSelectedLine', 'Delete selected line');
    Add('shDeleteLocation', 'Delete location');
    Add('shDeleteRoom', 'Delete Room');
    Add('shDeleteMarketSegment', 'Delete marketsegment');
    Add('shDeleteCustomer', 'Delete customer');
    Add('shDeleteStaffType', 'Delete stafftype');
    Add('shDeleteStaffMember', 'Delete staffMember');
    Add('shDeleteChannel', 'Delete channel');
    Add('shDeleteSystemServers', 'Delete SystemServer');
    Add('shDeleteSystemAction', 'Delete SystemAction');
    Add('shDeleteSystemTrigger', 'Delete SystemTrigger');
    Add('shDeletePackage', 'Delete Package');
    Add('shDeletePackageItem', 'Delete Package item');
    Add('shDeletePerson', 'Delete Person');
    Add('shDeleteVATCode', 'Delete VAT Code');
    Add('shDeleteBookKeepingCode', 'Delete book-keeping code');
    Add('shDeleteDynamicPriceRule', 'Delete the selected dynamic price rule?');
    //
    Add('shFilterOnRecordsOf', 'Filter on - %d records of %d are visible');
    Add('shEnterTextToFilterGrid', 'Enter text to filter grid');
    Add('shFilter', 'Filter : ');
    Add('shClear', 'Clear');
    Add('shExistsInRelatedData', 'exists in related data');
    Add('shCanNotDelete', 'can not delete');
    Add('shExistsInRelatedDataCannotDelete', '%s %s exists in related data' + #10 + 'Cannot delete!');
    Add('shContinue', 'Continue ?');
    Add('shNewValueExistInAnotherRecor', 'New value exist in another record. Use [ESC] to cancel');
    Add('shOldValueUsedInRelatedDataC', ' Old value used in related data can not change - Use [ESC] to cancel');
  end;
end;

procedure AddConstants_1;
begin
  with ConstantsDictionary do
  begin
    Add('shTx_AuthNeeded', '  Authentication needed...  ');
    Add('shTx_Available', 'Available');
    Add('shTx_ChannelAvailable', 'Channel');
    Add('shTx_Class', 'Class');
    Add('shTx_Authenticating', '  Authenticating...  ');
    Add('shTx_AuthSuccess', '  Authentication successful  ');
    Add('shTx_Taken', 'Taken');
    Add('shTx_NoRm', 'NoRm');
    Add('shTx_Free', 'Free');
    Add('shTx_Netto', 'Netto');
    Add('shTx_Cancelled', 'Cancel');
    Add('shTx_NoFilterActive', 'No filter is currently active.');
    Add('shTx_SearchAndFilterActive', 'Search for ''%s'' AND filter currently active.');
    Add('shTx_SearchActive', 'Search for ''%s'' currently active.');
    Add('shTx_FilterActive', 'Filter is currently active.');
    Add('shTx_FreeRoomsFilterActive', 'Filter on Rooms that are free for the next %d currently active.');
    Add('shTx_Location', 'Location');
    Add('shTx_Description', 'Description');
    Add('shTx_Floor', 'Floor');
    Add('shTx_NumGuests', 'Num guests');
    Add('shTx_ReportedBy', 'Reported by');
    Add('shTx_CleaningNotes', 'Cleaning notes');
   // Add('shTx_MaintenanceNotes', 'Mainteance notes');
    Add('shTx_MaintenanceNotes', 'Maintenance notes');
    Add('shTx_LostAndFount', 'Lost and found');
    Add('shTx_Equipment', 'Equipment');
    Add('shTx_Status', 'Status');
    Add('shTx_PerNight', '/night');
    Add('shTx_ReceivedVia', 'Received via');
    Add('shTx_ManuallyEnteredReservation', 'Manually entered reservation');
    Add('shTx_GroupAccount', 'Group account');
    Add('shTx_Note', 'NOTE');
    Add('shTx_UnpaidItemsOnInv', 'Unpaid items on invoice!');
    Add('shTx_NoUnpaidItemsOnInv', 'No unpaid items on invoice');
    Add('shTx_ReservationIdNotFound', 'Reservation %d not found. Please call Roomer support and provide this reservation number.!');
    Add('shTx_UnderDevelopment', 'Under development');
    Add('shTx_SaveToCurrencytable', 'Save to currencytable ' + chr(10) + 'Note : This will have effect on all ' + chr(10) + 'unBooked invoices ');
    Add('shTx_CurrencyUpdateError', 'Error updating currency rate');
    Add('shTx_CancelReservation2_RoomDescriptionAll', 'Room: [%s] %s. - Type: [%s] %s. - Location: %s');
    Add('shTx_CancelReservation2_GuestArrivalDeparture', 'Arrival: %s, Departure: %s');
    Add('shTx_CancelReservation3_RemovingAllRooms', 'Removing ALL rooms from reservation');
    Add('shTx_CancelReservation3_RemovingXRoomsOfYReservedRooms', 'Removing %d rooms of %d reserved rooms');
    Add('shTx_ChannelAvailabilityManager_IncorrectAvailability', 'Incorrect availability');
    Add('shTx_ChannelAvailabilityManager_EnterValidAvailability', 'Please enter a valid availability value');
    Add('shTx_ChannelAvailabilityManager_CurrentRates', 'Current rates on ');
    Add('shTx_ChannelAvailabilityManager_AllRoomTypes', 'All Room Types');
    Add('shTx_ChannelAvailabilityManager_AllPlanCodes', 'All Plan Codes');
    Add('shTx_ChannelAvailabilityManager_Availability', 'Availability');
    Add('shTx_ChannelAvailabilityManager_BulkAvailabilityUpdate', 'Bulk availability update');
    Add('shTx_ChannelAvailabilityManager_Rate', 'Rate');
    Add('shTx_ChannelAvailabilityManager_BulkRateUpdate', 'Bulk rate update');
    Add('shTx_ChannelAvailabilityManager_Availability2', 'AVAILABILITY');
    Add('shTx_ChannelAvailabilityManager_Rates', 'RATES');
    Add('shTx_ChannelAvailabilityManager_OnlineManagement', 'ONLINE MANAGEMENT');
    Add('shTx_ChannelAvailabilityManager_ChangesContinue', 'All changes will be lost. Continue?');
    Add('shTx_ChannelAvailabilityManager_ConfirmRemoveRates', 'NOTE: This will initiate removal of all current rates for the selected channel manager.'#13''#10''#13''#10'Afterwards rates will be re-read for all classes.'#13''#10''#13''#10' Continue?');
    Add('shTx_ChannelAvailabilityManager_EnterValidValue', 'Please enter a valid availability value');
    Add('shTx_ChannelAvailabilityManager_RoomAvailability', '%sAvailability: %s%d%s rooms.</font></font></body>');
  //  Add('shTx_ChannelManager_DescriptionRequired', 'Description is requierd - canceling insert - try again');
    Add('shTx_ChannelManager_DescriptionRequired', 'Description is required - canceling insert - try again');
  //  Add('shTx_ChannelManager_CodeRequired', 'Code is requierd - canceling insert - try again');
    Add('shTx_ChannelManager_CodeRequired', 'Code is required - canceling insert - try again');
    Add('shTx_ChannelManager_DescriptionError', 'Description');
    Add('shTx_ChannelManager_DescriptionError2', 'is required - Use ESC to cancel');
    Add('shTx_ChannelManager_EditInGrid', 'edit in grid');
    Add('shTx_Channels_UpdateNotOk', 'UPDATE NOT OK');
  //  Add('shTx_Channels_ChannelRequired', 'Channel is requierd - set value or use [ESC] to cancel ');
    Add('shTx_Channels_ChannelRequired', 'Channel is required - set value or use [ESC] to cancel ');
    Add('shTx_CommunicationTest_DayGuests', 'Current Day Guests ');
    Add('shTx_CommunicationTest_CustomerList', 'Full Customer list ');
   // Add('shTx_ControlData_NoAccount', 'Formskrá reiknings fannst ekki'#10'undir liðnum Reikningur er reitur '#10'til að staðsetja skránna '#10'Upphafsnafn (default name) hennar '#10'er islInvoice.fr3 ');
    Add('shTx_ControlData_NoAccount', 'Invoice Form not found'#10'in default location '#10'To locate the file '#10'Its default name '#10'is islInvoice.fr3 ');
   // Add('shTx_ControlData_Tax', 'Ath:  Það er ekki búið að skilgreina vörunúmer gistináttaskatts !');
    Add('shTx_ControlData_Tax', 'Note: Overnight tax code has not been specified');
   // Add('shTx_ControlData_Indent', 'Veldu undirlið %s');
    Add('shTx_ControlData_Indent', 'Select subitem %s');
   // Add('shTx_ControlData_NotAForm', '%s er ekki Formskrá (*.fr3) ');
    Add('shTx_ControlData_NotAForm', '%s is not a form (*.fr3) ');
    Add('shTx_ConvertGroups_CodeIsRequiredUseEsc', 'cgCode code - is required - Use ESC to cancel');
   // Add('shTx_ConvertGroups_CodeRequired', 'cgCode code is requierd - canceling insert - try again');
    Add('shTx_ConvertGroups_CodeRequired', 'cgCode code is required - canceling insert - try again');
    Add('shTx_ConvertGroups_NewData', 'Use editrow to add new data');
    Add('shTx_ConvertGroups_EditData', 'Use editrow to edit data');
    Add('shTx_Converts_TypeRequired', 'Convert Type - is required - Use ESC to cancel');
    Add('shTx_Countries_CodeRequired', 'Country code is required - canceling insert - try again');
    Add('shTx_Countries_CountryCodeIsRequired', 'Country code is required - Use ESC to cancel');

    Add('shTx_Currencies_Required', 'Currency required - set value or use [ESC] to cancel ');
    Add('shTx_Currencies_CodeIsRequired', 'Currency code - is required - Use ESC to cancel');
    Add('shTx_Currencies_RateCannotBeZeroCancel', 'Rate can not be 0 - Use ESC to cancel');
    Add('shTx_Currencies_EditInGrid', 'Edit in grid');

    Add('shTx_PersonVipType_Required', 'Peron VIP Type required - set value or use [ESC] to cancel ');
    Add('shTx_PersonVipType_CodeIsRequired', 'Person VIP Type code - is required - Use ESC to cancel');
    Add('shTx_PersonVipType_EditInGrid', 'Edit in grid');

    Add('shTx_PersonContactType_Required', 'Peron Contact Type required - set value or use [ESC] to cancel ');
    Add('shTx_PersonContactType_CodeIsRequired', 'Person Contact Type code - is required - Use ESC to cancel');
    Add('shTx_PersonContactType_EditInGrid', 'Edit in grid');

    Add('shTx_Roomtypes2_RoomTypeAlreadyExists', 'This room type already exists');
    Add('shTx_Rooms3_RoomAlreadyExists', 'This room already exists');
    Add('shTx_RoomtypeGroups_RoomTypeGroupAlreadyExists', 'This room class already exists');

    Add('shTx_CustomerEdit2_CustomerRequired', 'Customer is required');
    Add('shTx_CustomerEdit2_CustomerTypeRequired', 'Customer type is required');
    Add('shTx_CustomerEdit2_CustomerCountryRequired', 'Customer country is required');
    Add('shTx_CustomerEdit2_CustomerCurrencyRequired', 'Customer payment currency is required');
    Add('shTx_CustomerEdit2_CustomerPriceCoceRequired', 'Customer Rate code is required');

    Add('shTx_CustomerEdit2_CustomerExists', 'This customer exists ');
    Add('shTx_CustomerEdit2_NameRequired', 'Name is required');
   // Add('shTx_Customers2_Required', 'Customer requierd - set value or use [ESC] to cancel ');
    Add('shTx_Customers2_Required', 'Customer required - set value or use [ESC] to cancel ');
    Add('shTx_Customers2_InsertNotOk', 'INSERT NOT OK');
   // Add('shTx_CustomerTypes_RegistrationFilter', 'Nýskráning er utan síu og sést því ekki');
    Add('shTx_CustomerTypes_RegistrationFilter', 'Registration filtered and cannot be seen');
   // Add('shTx_CustomerTypes_DeleteCatagory', 'Eyða Viðskiptaaðilaflokk ');
    Add('shTx_CustomerTypes_DeleteCatagory', 'Delete customer group');
   // Add('shTx_CustomerTypes_AreYouSure', 'ertu viss ??');
    Add('shTx_CustomerTypes_AreYouSure', 'Are you sure ??');
    Add('shTx_CustomerTypes2_Description', 'Description ');
   // Add('shTx_CustomerTypes2_Required', 'is requierd - Use ESC to cancel');
    Add('shTx_CustomerTypes2_Required', 'is required - Use ESC to cancel');
   // Add('shTx_CustomerTypes2_CustomerTypeRequired', 'CustomerType is requierd - set value or use [ESC] to cancel ');
    Add('shTx_CustomerTypes2_CustomerTypeRequired', 'CustomerType is required - set value or use [ESC] to cancel ');
    Add('shTx_CustomerTypes2_Code', 'Code ');
    Add('shTx_CustomerTypes2_EditInGrid', 'Edit in grid');
    Add('shTx_D_UnableToSaveExceptionMessage', 'Problem: Unable to save the tmpInvoiveLines !' + #13#13 +
                                         'The following exception occurred:' + #13#13 +
                                         '%s' + #13#13 +
                                         'Please write this message down or' + #13 +
                                         'call support with this dialog open!');
    Add('shTx_D_UnpaidGroup', 'There are unpaid items on Group-invoice - resolve first');
    Add('shTx_D_UnpaidRoom', 'There are unpaid items on room-invoice  - resolve first');
   // Add('shTx_D_MaidActionsUnavailable', 'Taflan MaidActions ekki til staðar ');
    Add('shTx_D_MaidActionsUnavailable', 'The table MaidActions is not available ');
   // Add('shTx_D_TableUsingCannotDelete', 'Tegndar töflur nota %s. Ekki er því unnt að eyða.');
    Add('shTx_D_TableUsingCannotDelete', 'Related tables use %s. Cannot delete');
   // Add('shTx_D_RoomBeingUsedInReservations', 'Herbergi %s er notað í %d pöntunum. ' + #10 + 'Það er því ekki hægt að eyða því');
    Add('shTx_D_RoomBeingUsedInReservations', 'Room %s Is booked in %d reservation. ' + #10 + 'cannot be deleted');
    Add('shTx_D_CurrencyCancel', 'All rooms in Reservation must use same curency -  Canceling!');
    Add('shTx_D_DeleteRoom', 'Delete room from reservation ?');
   // Add('shTx_D_Cancel', 'Bókaðir reikningar eru á þessari pöntunn - Viltu hætta við ?');
    Add('shTx_D_Cancel', 'Invoices have been booked for this reservation - Do you want to cancel ?');
   // Add('shTx_D_InvoicesInDeletedBooking', 'Reikningar á eyddri bókun %s' + #10 +
   //                                       'Skrifið niður ef það á að gera kreditreikninga ');
    Add('shTx_D_InvoicesInDeletedBooking', 'Invoices in deleted booking %s' + #10 +
                                          'Write down the numbers if creating credit invoice ');
   // Add('shTx_D_OrderConfirm', 'Villtu örugglega setja þetta þessa herbergjapöntunn utan herbergja ?');
    Add('shTx_D_OrderConfirm', 'Are you sure you want this room reservation outside of the rooms?');
   // Add('shTx_D_AllRoomsToNoRoom', 'Viltu örugglega setja ÖLL herbergi pöntunnar ' + #10 +
   //                                       'utan herbergja ?');
    Add('shTx_D_AllRoomsToNoRoom', 'Are You sure you want ALL room reservations' + #10 +
                                          'outside of room?');
   // Add('shTx_D_FolderNotFound', 'Mappan %s fannst ekki.' + #10 +
   //                                       'Skráin verður vistuð í %s');
      Add('shTx_D_FolderNotFound', 'Folder not found' + #10 +
                                          'The file will be saved in %s');
   // Add('shTx_D_PathChange', 'Skráin verður vistuð í %s');
    Add('shTx_D_PathChange', 'File will be saved in %s');
   // Add('shTx_D_AccountReadContinue', 'Það er þegar búið að útlesa reikning %s %d sinnum.' + #10 +
   //                                       'Halda áfram með útlestur ??');
    Add('shTx_D_AccountReadContinue', 'When the account %s has been read %d times.' + #10 +
                                          'Continue reading ??');
    Add('shTx_D_CheckoutXDaysAgo', 'Should have checked out %d days ago');
    Add('shTx_D_CheckoutYesterday', 'Should have checked out yesterday ');
    Add('shTx_D_LeavesToday', 'Leaves today');
    Add('shTx_D_LeavesTomorrow', 'Leaves tomorrow');
    Add('shTx_D_LeavesAfterXDays', 'Leaves after %d days');
    Add('shTx_D_CheckedIn', 'Guest is Checked in ');
    //Add('shTx_D_AddedNoLogin', 'Added without loggin in');
    Add('shTx_D_AddedNoLogin', 'Added without logging in');
    Add('shTx_D_CheckDates', 'Check dates - 0 days ');
    Add('shTx_D_SomeErrors', ' Some errors ');
    Add('shTx_D_Total', ' total ');
  //  Add('shTx_D_OnlyChangeDeparture', 'ATH Aðeins er hægt að breyta brottfarardegi ');
    Add('shTx_D_OnlyChangeDeparture', 'note: Only checkout date can be changed ');
    Add('shTx_D_InvoicesBooked', 'Invoices have been booked for this reservation - Cancel the deletion?');
    Add('shTx_D_InvoicesBookedNumbersWriteDown', 'Invoices have been booked for this reservation' + #10 +
                                            'Numbers : %s' + #10 +
                                            'Write down the numbers if they need to be credited ');
    Add('shTx_D_DeleteAll', 'Delete all rooms in reservation ?');
   // Add('shTx_D_RoomAlreadyCheckedin', 'Herbergi %s er þegar innskráð.');
    Add('shTx_D_RoomAlreadyCheckedin', 'Room %s is already checked in.');
    Add('shTx_DayFinical_NoInvoices', 'There are no unconfirmed invoices');
    Add('shTx_DayFinical_NoInvoicesForFromToDate', 'There are no invoices for %s - %s');
    Add('shTx_DayFinical_NoConfirmedInvoicesFor', 'There are no confirmed invoices for %s');
    Add('shTx_DayFinical_NoInvoices2', 'There is no Confirmed invoices');
    Add('shTx_DayFinical_InvoiceConfirmed', 'Invoiced has been confirmed - unconfirm now!');
   // Add('shTx_DayFinical_NoUnconfirmedInvoices', 'There is no unConfirmed invoices'); - breytti 'C' i 'c'
    Add('shTx_DayFinical_NoUnconfirmedInvoices', 'There is no unconfirmed invoices');
    Add('shTx_DayFinical_InvoiceNotConfirmed', 'Invoiced not confirmed - confirm now!');
    Add('shTx_DayFinical_Unconfirm', 'Un-confirm NOW');
    Add('shTx_DayFinical_Confirm', 'Confirm NOW');
    Add('shTx_DayFinical_CashInvoice', 'This is is a cash invoice');
    Add('shTx_DayFinical_GroupInvoice', 'This is a group invoice');

   (* Add('shTx_DayStats_RoomRental', 'Óreikningsfærð Herbergjaleiga ');
    Add('shTx_DayStats_Discount', 'Afsláttur ');
    Add('shTx_DayStats_Total', 'Samtals ');
    Add('shTx_DayStats_File', 'Skráin ');
    Add('shTx_DayStats_NotFound', ' fannst ekki ');
    Add('shTx_DayStats_CreateTable', 'Búa til töflur');
    Add('shTx_DayStats_ErrorDeleted', 'Villa - Delete');
    Add('shTx_DayStats_GetUninvoicedRoom', 'Sækja óreikningsfærða heibergjaleigu ');
    Add('shTx_DayStats_GetUninvoicedGoods', 'Sækja óreikningsfærðar vörur ');
    Add('shTx_DayStats_UninvoicedGroupGoods', 'Sækja óreikningsfærðar vörur á hópreikningum');
    Add('shTx_DayStats_GetInvoicedAccounts', 'Sækja Reikningsfært af herbergja reikningum');
    Add('shTx_DayStats_Error1', 'Villa 1');
    Add('shTx_DayStats_Error2', 'Villa 2');
    Add('shTx_DayStats_Error3', 'Villa 3');
    Add('shTx_DayStats_Error4', 'Villa 4');
    Add('shTx_DayStats_NumberOfBookings', 'Fjöldi pantana ');
    Add('shTx_DayStats_GroupInvoice', ' Reikningsfært á hópreikningi ');
    Add('shTx_DayStats_RoomRent', 'Herbergjaleiga');
    Add('shTx_DayStats_DiscountRoomRent', 'Afsláttur af herbergjaleigu ');
    Add('shTx_DayStats_TotalRoomRent', 'Samtals Herbergjaleiga');
    Add('shTx_DayStats_Products', 'Vörur ');
    Add('shTx_DayStats_TotalSales', 'Samtals Velta ');
    Add('shTx_DayStats_CalcF', 'Reikn.f  ');
    Add('shTx_DayStats_CalcF2', 'Óreikn.f '); *)

    Add('shTx_DayStats_RoomRental', 'Uninvoiced Room Rental ');
    Add('shTx_DayStats_Discount', 'Discount ');
    Add('shTx_DayStats_Total', 'Total ');
    Add('shTx_DayStats_File', 'File ');
    Add('shTx_DayStats_NotFound', ' Not found ');
    Add('shTx_DayStats_CreateTable', 'Create table');
    Add('shTx_DayStats_ErrorDeleted', 'Error - deleted');
    Add('shTx_DayStats_GetUninvoicedRoom', 'Get uninvoiced room rental ');
    Add('shTx_DayStats_GetUninvoicedGoods', 'Get uninvoiced goods ');
    Add('shTx_DayStats_UninvoicedGroupGoods', 'Get uninvoiced goods in group');
    Add('shTx_DayStats_GetInvoicedAccounts', 'Get invoiced accounts');
    Add('shTx_DayStats_Error1', 'Error 1');
    Add('shTx_DayStats_Error2', 'Error 2');
    Add('shTx_DayStats_Error3', 'Error 3');
    Add('shTx_DayStats_Error4', 'Error 4');
    Add('shTx_DayStats_NumberOfBookings', 'Number of bookings ');
    Add('shTx_DayStats_GroupInvoice', ' Invoiced on group invoice ');
    Add('shTx_DayStats_RoomRent', 'Room rent');
    Add('shTx_DayStats_DiscountRoomRent', 'Discount of room rental ');
    Add('shTx_DayStats_TotalRoomRent', 'Total room rental');
    Add('shTx_DayStats_Products', 'Products ');
    Add('shTx_DayStats_TotalSales', 'Total Sales ');
    Add('shTx_DayStats_CalcF', 'calc.f  ');
    Add('shTx_DayStats_CalcF2', 'calc.f ');

    Add('shTx_FinishedInvoices2_NoFinishedInvoices', 'No finished invoices found for your selection');
    Add('shTx_FinishedInvoices2_Product', 'Product');
    Add('shTx_FinishedInvoices2_Description', 'Description');
    Add('shTx_FinishedInvoices2_Number', 'Number');
    Add('shTx_FinishedInvoices2_Value', 'Value');
    Add('shTx_FinishedInvoices2_Total', 'Total');
    Add('shTx_FinishedInvoices2_Category', 'Category');
    Add('shTx_FinishedInvoices2_Amount', 'Amount');
    Add('shTx_FinishedInvoices2_VAT', 'VAT');
    Add('shTx_FinishedInvoices2_Date', 'Date');
    Add('shTx_FinishedInvoices2_FileNotFound', 'File %s not found ');
    Add('shTx_FinishedInvoices2_NoChange', 'This account will be recreated - no change is made to older account');
    Add('shTx_FormCustomInvoicesMD_AllCustomers', 'All Customers');
    Add('shTx_FormCustomInvoicesMD_SelectCustomer', 'Select Customer');
    Add('shTx_FormCustomInvoicesMD_OneDayDate', 'One Day - select date');
    Add('shTx_FormCustomInvoicesMD_PeriodDate', 'Period - select dates');
    Add('shTx_FormCustomInvoicesMD_WrongDate', 'Wrong date selection');

   (* Add('shTx_G_NotArrived', 'Ókominn');
    Add('shTx_G_CheckedIn', 'Innskráður');
    Add('shTx_G_CheckedOut', 'Farinn');
    Add('shTx_G_WaitingList', 'Biðlisti'); *)

    Add('shTx_G_DueToArrive', 'Due to arrive');
    Add('shTx_G_NotArrived', 'Not Arrived');
    Add('shTx_G_CheckedIn', 'Checked In');
    Add('shTx_G_CheckedOut', 'Checked Out');
    Add('shTx_G_WaitingList', 'Waiting List');
    Add('shTx_G_Alotment', 'Allotment');
    Add('shTx_G_NoShow', 'No show');
    Add('shTx_G_Blocked', 'Blocked');
    Add('shTx_G_DepartingToday', 'Due to check out');
    Add('shTx_G_Cancelled', 'Cancelled');

   // Add('shTx_G_Downpayment', 'Downpayment/innágreiðsla');
    Add('shTx_G_Downpayment', 'Downpayment');
    Add('shTx_G_ConnectionFail', 'Connection failure!');
    Add('shTx_G_ConnectionSuccess', 'Connection successful!');
    Add('shTx_G_DeleteRooms', 'Delete selected rooms from reservation ?' + #10 +
                                            'Rooms : %s');
    Add('shTx_G_Reservation', 'Reservation');
    Add('shTx_G_Guest', 'Guest');
    Add('shTx_G_Departed', 'Departed');
    Add('shTx_G_Reserved', 'Reserved');
    Add('shTx_G_Overbooked', 'Overbooked');
    Add('shTx_G_Departing', 'Departing');
    Add('shTx_G_Current', 'Current');
    Add('shTx_G_Canceled', 'Canceled'); //*HJ 140206
    Add('shTx_G_Tmp1', 'Tmp1'); //*HJ 140206
    Add('shTx_G_Tmp2', 'Tmp2'); //*HJ 140206

    Add('shTx_GotoRoomAndDate_RoomNotFound', 'RoomReservation not Found');
    Add('shTx_GotoRoomAndDate_ReservationNotFound', 'Reservation not Found');
    Add('shTx_GotoRoomAndDate_CashNoRoom', 'Cash invoice - No Room');
    Add('shTx_GotoRoomAndDate_InvoiceNotFound', 'Invoice not found');
  end;
end;

procedure AddConstants_2;
begin
  with ConstantsDictionary do
  begin
    Add('shTx_GuestProfile2_SplitRoom', 'split room to new reservation');
    Add('shTx_GuestProfile2_UnableToSplitRoom', 'Problem: Unable to split room to new reservation ' + #13#13 +
                                  'The following exception occurred:' + #13#13 +
                                  '%s' + #13#13 +
                                  'Please write this message down or' + #13 +
                                  'call support with this dialog open!');
    Add('shTx_GuestProfile2_NameChange', 'Reservation Name changed - sure ?');
    Add('shTx_GuestProfile2_RoomsInReservation', '%d rooms in this reservation with total %d guests');
    Add('shTx_GuestProfile2_RoomNoWithGuests', 'Room no. %s with %d guests');
    Add('shTx_GuestProfile2_NotesForRoom', 'Notes for room no. %s');
    Add('shTx_GuestProfile2_Person', 'Person');
   // Add('shTx_GuestProfile2_NameRequired', 'Person name requierd - set value or use [ESC] to cancel ');
    Add('shTx_GuestProfile2_NameRequired', 'Person name required - set value or use [ESC] to cancel ');
    Add('shTx_GuestProfile2_EditInGrid', 'edit in grid');
    Add('shTx_GuestProfile2_ReservationSame', 'Reservation target can not be same reservation');
    Add('shTx_GuestProfile2_ReservationNotFound', 'Reservation target not found');
    Add('shTx_GuestProfile2_MoveReservationNewResNewCust', 'Move this room to another reservation ' + #10 +
                                  'New Reservation : %s' + #10 +
                                  'New Customer : %s');
    Add('shTx_GuestProfile2_ChangeRoom', 'Change room to another reservation');
    Add('shTx_GuestProfile2_ProblemChange', 'Problem: Move room to another reservation' + #13#13 +
                                  'The following exception occurred:' + #13#13 +
                                  '%s' + #13#13 +
                                  'Please write this message down or' + #13 +
                                  'call support with this dialog open!');
    Add('shTx_GuestProfile2_NoRooms', 'No Rooms is in reservation %d');
    Add('shTx_HiddenInfo_CreateNew', 'Create New ?');
    Add('shTx_HiddenInfo_SaveChanges', 'Save changes ?');
    Add('shTx_HouseKeeping_Created', 'Create at : %s');
    Add('shTx_HouseKeeping_User', 'User : %s');

    Add('shTx_HouseKeeping_Code_O', 'Out of order');
    Add('shTx_HouseKeeping_Code_M', 'Maintenance Needed');
    Add('shTx_HouseKeeping_Code_S', 'Clean but needs maintenance');
    Add('shTx_HouseKeeping_Code_F', 'Maintenance in progress');
    Add('shTx_HouseKeeping_Code_W', 'Being Cleaned');
    Add('shTx_HouseKeeping_Code_U', 'Not Clean');
    Add('shTx_HouseKeeping_Code_R', 'Ready For Inspection');
    Add('shTx_HouseKeeping_Code_C', 'Clean');
    Add('shTx_HouseKeeping_Code_L', 'Wait For Checkout');
    Add('shTx_HouseKeeping_Code_D', 'Do Not Disturb');
    Add('shTx_HouseKeeping_Code_', 'Unknown status');

    Add('shTx_HouseKeeping_NumberOfGuests', ' %d guests.');
    Add('shTx_HouseKeeping_GuestWaitingForGuestToDepart', 'Wait for guest to depart.');
    Add('shTx_HouseKeeping_GuestDepartedNewArrival', 'Guests departed, new arrival.');
    Add('shTx_HouseKeeping_GuestDepartedNoNewArrival', 'Guests departed, No arrival.');
    Add('shTx_HouseKeeping_GuestLeavesToday', 'Guests Leaves today, new arrival.');
    Add('shTx_HouseKeeping_LeavesTomorrow', 'which leaves tomorrow. ');
    Add('shTx_HouseKeeping_StayingForDays', 'staying for %d days.');
    Add('shTx_HouseKeeping_ArrivesToday', 'Guest arrives today.');
    Add('shTx_HouseKeeping_TodayNoArrival', 'Guest leaves today. No arrival. ');
    Add('shTx_HouseKeeping_GuestTomorrow', 'Guest leaves tomorrow. ');
    Add('shTx_HouseKeeping_CheckinNever', ' - Next Checkin unknown. ');
    Add('shTx_HouseKeeping_NextTomorrow', ' - Next Tomorrow. ');
    Add('shTx_HouseKeeping_CheckinAfterDays', ' - Next Checkin after %d days.');
    Add('shTx_HouseKeeping_RoomUnoccupied', 'Room is and stays unoccupied.');
    Add('shTx_HouseKeeping_OccupiedXDays', 'Occupied. Guest stays for %d more days.');
    Add('shTx_HouseKeeping_Beds', 'Beds');
    Add('shTx_HouseKeeping_CleaningSuspended', 'Suspend cleaning!');
    Add('shTx_HouseKeeping_FullCleaning', 'Prepare for new guests');
    Add('shTx_HouseKeeping_FullCleaningAdditionalBed', 'Prepare for new guests. Add extra bed.');
    Add('shTx_HouseKeeping_DailyCleaning', '50% - Daily Cleaning.');
    Add('shTx_HouseKeeping_DailyCleaningPlusBeds', '50% - Daily Cleaning + Beds.');
    Add('shTx_HouseKeeping_SpecialRequirements', 'Special Requirements');
    Add('shTx_HouseKeeping_RoomStatusDate', 'Room Status - Date : %s');
    Add('shTx_Invoice_SaveInvoice', 'Save invoice and room price changes?');
    Add('shTx_Invoice_SaveChanges', 'Save invoice changes?');
    Add('shTx_Invoice_NotANumber', '%s is not a number');
    Add('shTx_Invoice_InvoiceNumber', 'Invoice number %s not found');
    Add('shTx_Invoice_CreditInvoice', 'This is a credit invoice');
   // Add('shTx_Invoice_Value_Unchangeable', 'Gildi [%s] eru meðhöndluð af kerfinu og því ekki hægt að breyta ');
    Add('shTx_Invoice_Value_Unchangeable', 'Value [%s] is handled by the system and cannot be changed');
    Add('shTx_Invoice_NotAllowed', 'You are not allowed to use the System''s Payment code directly');
    Add('shTx_Invoice_UnableToSaveInvoiceMessage', 'Problem: Unable to save the invoice!' + #13#13 +
                                               'While saving invoice the following exception occurred:' + #13#13 +
                                               '%s' + #13#13 +
                                               'Please write this message down or' + #13 +
                                               'call support with this dialog open!');
    Add('shTx_Invoice_UnableSavePaymentsMessage', 'Problem: Unable to save the Payments !' + #13#13 +
                                               'While saving payments the following exception occurred:' + #13#13 +
                                               '%s' + #13#13 +
                                               'Please write this message down or' + #13 +
                                               'call support with this dialog open!');
    Add('shTx_Invoice_PaymentTotalInvoice', 'Payment needs to total to the same amount as the total invoice');
    Add('shTx_Invoice_CreatingInvoice', 'Creating Invoice ');
    Add('shTx_Invoice_OpenInvoiceAfterPrintCredit', 'Open a new invoice with the original amounts' + #10 +
                                               'when finished printing credit invoice ?');
    Add('shTx_Invoice_GroupInvoice', 'This is a Group invoice');
    Add('shTx_Invoice_RoomInvoice', 'Cannot move the item to the same room invoice.');
    Add('shTx_Invoice_RoomrentToGroupAndSaveChanges', 'Move roomrent to Group invoice ' + #10 +
                                               'and save other changes ?');
    Add('shTx_Invoice_RoomrentToRoomAndSaveChanges', 'Move roomrent to Room invoice ' + #10 +
                                               'and save other changes ?');
   // Add('shTx_Invoice_ReferenceNumberNotFound', 'Tilvísunarnúmer %d fannst ekki ');
    Add('shTx_Invoice_ReferenceNumberNotFound', 'Reference number %d not found ');
    Add('shTx_Invoice_Nights', 'Nights.');
    Add('shTx_Invoice_SaveChanges2', 'Save changes');
    Add('shTx_Invoice_PPNotAllowed', 'Print and pay not allowed while performing price changes');
    Add('shTx_Invoice_CurrencyDifferent', 'Customer''s currency is different from currency of this invoice.');
    Add('shTx_Invoice_PrintAndPay', 'Print and pay not allowed when in price changes');
    Add('shTx_Invoice_DeleteItem', 'Delete item ');
    Add('shTx_Invoice_DeleteSelectedItems', 'Delete selected items ');
    Add('shTx_Invoice_SetTemp', 'Set room to temp ');
    Add('shTx_Invoice_SaleNotSelected', 'Sale item not selected !');
    Add('shTx_Invoice_TakeItemFromInvoice', 'Take [%s] from invoice?');
    Add('shTx_Invoice_CanNotDelete', 'System item can not delete ');

   (* Add('shTx_Invoice_BlankLine', 'Auð lína');
    Add('shTx_Invoice_ErrorInTotal', 'villa í upphæð %s');
    Add('shTx_Invoice_MoveItemToGroupInvoice', 'Viltu færa %s: %s' + #10 +
                                               'á hópreikning ');
    Add('shTx_Invoice_FailedGroupInvoice', 'Ekki tókst að uppfæra Hópreikning - Hætt við ' + #10 +
                                               'Villa : %s'); *)
											 
    Add('shTx_Invoice_BlankLine', 'Blank Line');
    Add('shTx_Invoice_ErrorInTotal', 'Error in total %s');
    Add('shTx_Invoice_MoveItemToGroupInvoice', 'Move item %s: %s' + #10 +
                                               'to group invoice? ');
    Add('shTx_Invoice_MoveSelectedItemsToGroupInvoice', 'Move selected items to group invoice? ');
    Add('shTx_Invoice_MoveItemToRoomInvoice', 'Move item %s: %s' + #10 +
                                               'to room %s? ');
    Add('shTx_Invoice_FailedGroupInvoice', 'Moving to group invoice failed - Cancel ' + #10 +
                                               'Error : %s');
											 
    Add('shTx_Invoice_EmptyInvoice', 'Empty invoiceline');
    Add('shTx_Invoice_CompressionNotReversibleMessage',
                                               'Compressing the room rental lines is not reversible.' + #13#13 +
                                               'After compressing the lines, you will need to manage the prices' + #13 +
                                               'and all related issues manually without the system interfering.' + #13#13 +
                                               'Please confirm by clicking [Yes] or [Cancel] the process.');
											 
   (* Add('shTx_InvoiceList2_BookingNumber', 'Númer bókunnar er tala');
    Add('shTx_InvoiceList2_CashAccount', 'Þetta er staðgreiðslureikningur');
    Add('shTx_InvoiceList2_GroupInvoice', 'Þetta er hópreikningur');
    Add('shTx_InvoiceList2_NotRoomInvoice', 'Þessi reikninguer er ekki herbergjareikningur'); *)

    Add('shTx_InvoiceList2_BookingNumber', 'Booking Number is a number');
    Add('shTx_InvoiceList2_CashAccount', 'This is a cash invoice');
    Add('shTx_InvoiceList2_GroupInvoice', 'This is a group invoice');
    Add('shTx_InvoiceList2_NotRoomInvoice', 'This invoice is not the Room invoice');
    Add('shTx_InvoiceList2_NoRoomFound', 'No room found');

    Add('shTx_InvoicePayment_DownPayment', 'Down payment');
    Add('shTx_InvoicePayment_InvoicePayment', 'Invoice Payment');
    Add('shTx_InvoicePayment_ConfirmCode', 'Confirm code');
    Add('shTx_InvoicePayment_Code', 'Code :');
    Add('shTx_InvoicePayment_ExceedsInvoice', 'Payments exceed total invoice?!');
    Add('shTx_Items2_ItemTypeRequired', 'Item type is required - set value or use [ESC] to cancel ');
  //  Add('shTx_Items2_ItemRequired', 'Item is requierd - set value or use [ESC] to cancel ');
    Add('shTx_Items2_ItemRequired', 'Item is required - set value or use [ESC] to cancel ');
    Add('shTx_Items2_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_Items2_ItemCodeIsRequired', 'Item code - is required - Use ESC to cancel');
    Add('shTx_Items2_Required', 'is required - Use ESC to cancel');
    Add('shTx_Items2_EditInGrid', 'Edit in grid');
    Add('shTx_Items2_Item', 'Item');
    Add('shTx_ItemsTypes2_UpdateNotOk', 'UPDATE NOT OK');
   // Add('shTx_ItemsTypes2_ItemTypeRequired', 'ItemType is requierd - set value or use [ESC] to cancel ');
   Add('shTx_ItemsTypes2_ItemTypeRequired', 'ItemType is required - set value or use [ESC] to cancel ');
   // Add('shTx_ItemsTypes2_VATCodeRequired', 'VAT code is requierd - set value or use [ESC] to cancel ');
   Add('shTx_ItemsTypes2_VATCodeRequired', 'VAT code is required - set value or use [ESC] to cancel ');
    Add('shTx_ItemsTypes2_InsertNotOK', 'INSERT NOT OK');
    Add('shTx_ItemsTypes2_Description', 'Description ');
    Add('shTx_ItemsTypes2_Required', 'is required - Use ESC to cancel');
    Add('shTx_ItemsTypes2_ItemCode', 'Item code ');
    Add('shTx_ItemsTypes2_VATCode', 'VAT code ');
    Add('shTx_ItemsTypes2_EditInGrid', 'Edit in grid');
   Add('shTx_Locations2_LocationRequired', 'Location is required - set value or use [ESC] to cancel ');
    Add('shTx_Locations2_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_Locations2_EditInGrid', 'Edit in grid');


    Add('shTx_MaidActions_RegisterNotFound', 'Registration outside of filer, not found');
    Add('shTx_MaidActions_DeleteMaidAction', 'Delete Maid Action %s: %s' + #10 +
                                                'Are You Sure ?');
    Add('shTx_MaidActionsEdit_CodeMaidAction', 'Maid Action Code mude be specified');
    Add('shTx_MainActionsEdit_MaidActionAvailable', 'Maid Action Available - Try Again');
    Add('shTx_MainActionsEdit_NameMaid', 'Maid Action Name must be specified.');
  
    Add('shTx_Main_AutoLoggedOff', '  Automatically logged off due to inactivity.');
    Add('shTx_Main_Downloading', 'Downloading...');
    Add('shTx_Main_Ready', 'Ready.');
    Add('shTx_Main_LoggedOut', '  User logged out.');
    Add('shTx_Main_DepricatedFunction', 'Depricated function. Please open Room Profile to change settings.');
    Add('shTx_Main_ForcedLogout', '  Server forced logout.');
    Add('shTx_Main_LogginAgain', '  Please try logging in again in a few seconds...');
    Add('shTx_Main_ReservationCancelled', 'Reservation Canceled');
    Add('shTx_MakeBlockReservation_PriceFor', 'price for ');
    Add('shTx_MakeBlockReservation_Currency', ' and Currency ');
    Add('shTx_MakeBlockReservation_NotFound', ' not found !!');
    Add('shTx_MakeBlockReservation_NotFound2', '** Not Found **');
    Add('shTx_MakeReservationBH_PriceFor', 'Price for ');
  end;
end;

procedure AddConstants_3;
begin
  with ConstantsDictionary do
  begin
    Add('shTx_QuickReservation_NewReservationQuick', 'New Reservation - Quick Mode');
    Add('shTx_QuickReservation_NewReservation', 'New Reservation');
    Add('shTx_ManageFiles_Delete', 'Do you want to delete file "%s"?');
    Add('shTx_ManageFiles_UnableToUpload', 'Unable to upload file "%s"');
    Add('shTx_ManageFiles_RetrieveList', 'Please first retrieve the list of files to be worked with (ReadFileList)');
    Add('shTx_NationalReport_Created', 'Created : ');
    Add('shTx_NationalReport_User', 'User : ');
    Add('shTx_NationalReport_ChangeNationalityFromTo', 'Change nationality of all guests ' + #10 +
                                        ' from %s to %s ' + #10 +
                                        'Confirm ?');
    Add('shTx_NationalReport_NoChangeCountry', 'Not able to change country');
    Add('shTx_OpenInvoiceNew_NotValidNumber', 'Not Valid Reservation Number');
    Add('shTx_OpenInvoiceNew_Group', 'Group');
    Add('shTx_OpenInvoiceNew_CashInvoice', 'This is a cash invoice');
    Add('shTx_OpenInvoiceNew_CashInvoice2', 'This is cash invoice - not related to any reservation');
    Add('shTx_OpenInvoiceNew_Guest', 'Guest');
    Add('shTx_OpenInvoiceNew_NotArrived', 'Not Arrived');
    Add('shTx_OpenInvoiceNew_Departed', 'Departed');
    Add('shTx_OpenInvoiceNew_NoShow', 'No Show');
    Add('shTx_OpenInvoiceNew_Allotment', 'Allotment');
    Add('shTx_OpenInvoiceNew_WaitingList', 'Waitinglist');
    Add('shTx_OpenInvoiceNew_Blocked', 'Blocked');
    Add('shTx_OpenInvoiceNew_Unknown', 'Unknown');
    Add('shTx_PackagedItems_UpdateNotOK', 'UPDATE NOT OK');
    Add('shTx_PackagedItems_DescriptionRequired', 'Description is required - set value or use [ESC] to cancel ');
    Add('shTx_PackagedItems_ItemRequired', 'Item is required - set value or use [ESC] to cancel ');
    Add('shTx_PackagedItems_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_PackagedItems_ItemIsRequired', 'Item - is required - Use ESC to cancel');
    Add('shTx_Packages_PackageRequired', 'Package is required - set value or use [ESC] to cancel ');
    Add('shTx_Packages_Package', 'Package');
    Add('shTx_Packages_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_Packages_PackageCodeIsRequired', 'Package code - is required - Use ESC to cancel ');
    Add('shTx_Packages_Exists', 'exists in Items table ');
    Add('shTx_ReservationProfile_MustBeOver1Day', 'Number of days must be atleast 1 day - Check the dates ! ');
    Add('shTx_ReservationProfile_CopyHidden', 'Copy to hidden :');
    Add('shTx_ReservationProfile_ChangeNationalityConfirmation',
                                       //   'Breyta þjóðerni allra gesta pöntunnar ' + #10 +
                     'Change nationality of all guests ' + #10 +
                                       //   ' from %s to %s.' + #10#10 +
                     ' From %s to %s.' + #10#10 +
                                       //   'Ertu viss ?');
                      'Confirm ?');
  //  Add('shTx_ReservationProfile_NationalityChangeFailed', 'Ekki tókst að breyta landi');
    Add('shTx_ReservationProfile_NationalityChangeFailed', 'Changing nationality failed');
    Add('shTx_ReservationProfile_Outdated', 'OutDated');
    Add('shTx_ReservationProfile_ChangeAllRooms', 'Change all rooms to ');
    Add('shTx_ReservationProfile_BreakfastInc', 'Breakfast included ?');
    Add('shTx_ReservationProfile_BreakfastNotInc', 'Breakfast NOT included ?');
    Add('shTx_ReservationProfile_GroupAccount', 'Group Account ?');
    Add('shTx_ReservationProfile_RoomAccount', 'Room Account ?');
    Add('shTx_ReservationProfile_NotArrived', 'Not arrived');
    Add('shTx_ReservationProfile_CheckedIn', 'Checked in');
    Add('shTx_ReservationProfile_Departed', 'Departed');
    Add('shTx_ReservationProfile_WaitingList', 'Waitinglist');
    Add('shTx_ReservationProfile_Allotment', 'Allotment');
    Add('shTx_ReservationProfile_NoShow', 'No-show');
    Add('shTx_ReservationProfile_Blocked', 'Blocked');
    Add('shTx_ReservationProfile_canceled', 'Canceled');
    Add('shTx_ReservationProfile_Tmp1', 'Other 1');
    Add('shTx_ReservationProfile_Tmp2', 'Other 2');
    Add('shTx_ReservationProfile_ChangeStatus', 'Change status on all room reservations in %s?' + #10);
    Add('shTx_ReservationProfile_MoreThanOneRoomUseForm', 'More than one room in Reservation ' + #10 +
                                            'Use RoomReservation Form - for each room to change ');
    Add('shTx_ReservationProfile_AddRoomError', 'Add Room error : %s');

    Add('shTx_RoomPricesEdit_RoomType', 'Room Type must be specified');
    Add('shTx_RoomPricesEdit_PriceTime', 'Price range must be specified');
    Add('shTx_RoomPricesEdit_Invoice', 'Invoice must be specified');
    Add('shTx_RoomPricesEdit_NamePrice', 'Price description is required');
    Add('shTx_RoomPricesEdit_Prices', 'Prices are ready');
    Add('shTx_RoomPricesEdit_Error', 'Error');
    Add('shTx_RoomPricesEdit_PriceGroup', 'Price Group must be specified');

    Add('shTx_RoomRates_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_RoomRates_EditInGrid', 'edit in grid');
    Add('shTx_StaffMembers2_StaffMember', 'Staffmember');
  //  Add('shTx_StaffMembers2_InitialsRequired', 'Initials are requierd - set value or use [ESC] to cancel ');
    Add('shTx_StaffMembers2_InitialsRequired', 'Initials are required - set value or use [ESC] to cancel ');
    Add('shTx_StaffMembers2_InitialIsRequired', 'Initial - is required - Use ESC to cancel');
    Add('shTx_StaffMembers2_NameIsRequired', 'Name - is required - Use ESC to cancel');
   // Add('shTx_Room2_RoomRequired', 'Room is requierd - set value or use [ESC] to cancel ');
    Add('shTx_Room2_RoomRequired', 'Room is required - set value or use [ESC] to cancel ');
    Add('shTx_Room2_UpdateNotOK', 'UPDATE NOT OK');
    Add('shTx_Room2_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_Room2_EditInGrid', 'edit in grid');
    Add('shTx_SystemActions_UpdateNotOK', 'UPDATE NOT OK');
    Add('shTx_SystemActions_DescriptionRequired', 'Descriprion is required - set value or use [ESC] to cancel ');
    Add('shTx_SystemActions_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_SystemActions_EditInGrid', 'edit in grid');
    Add('shTx_Rates_DescriptionRequired', 'Description is required - set value or use [ESC] to cancel ');
    Add('shTx_Rates_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_Rates_DefaultForCurrenyAlreadyExists', 'Default for %s already exists - Use [ESC] to abandon changes');
    Add('shTx_Rates_CurrencyIsRequired', 'Currency - is required');
    Add('shTx_Rates_DefaultExistsAbandonChanges', 'Default for %s already exists - abandoning changes');
    Add('shTx_Rates_EditInGrid', 'edit in grid');
  end;
end;

procedure AddConstants_4;
begin
  with ConstantsDictionary do
  begin
    Add('shTx_RoomTypeGroups2_RoomclassRequired', 'Room class code is required - set value or use [ESC] to cancel ');
    Add('shTx_RoomTypeGroups2_RoomClassIsRequired', 'Room class - is required - Use ESC to cancel');
    Add('shTx_RoomTypeGroups2_EditInGrid', 'edit in grid');
    Add('shTx_PriceCodes_Pricecode', 'Pricecode');
    Add('shTx_PriceCodes_PriceRequired', 'Pricecode required - set value or use [ESC] to cancel ');
    Add('shTx_PriceCodes_CodeIsRequired', 'Code - is required - Use ESC to cancel');
    Add('shTx_PriceCodes_RackRate', 'There can only be one rackrate - Use [ESC] to abandon changes');
    Add('shTx_PriceCodes_EditInGrid', 'edit in grid');
    Add('shTx_TelLog_OneDay', 'One Day - select date');
    Add('shTx_TelLog_Period', 'Period - select dates');
    Add('shTx_TelLog_ComingSoon', 'Coming Soon');
    Add('shTx_TelLog_WrongDate', 'Wrong date selection');
    Add('shTx_RoomProfile_Customer', 'Customer : %s');
    Add('shTx_RoomProfile_NumberDoesntExist', 'This reservation number does not exists ');
    Add('shTx_RoomProfile_RoomStatusChangedChangeAllReservation', 'Room status changed to %s.' + #13#13 +
                                          'Change the whole reservation?');
    Add('shTx_RoomProfile_SameSettingsToAllReservation', 'Would you like to assign the same settings to all the rooms' + #10 +
                                          'in this reservation ?');
    Add('shTx_ChangeRRdates_CheckDates', 'Check dates - 0 days ');
    Add('shTx_ChangeRRdates_SomeErrors', ' Some errors ');
    Add('shTx_ChangeRRdates_Total', ' total ');

    Add('shTx_ChangeRRdates_ErrorSameDate', 'Error - checkin and checkout dates are the same');
    Add('shTx_ChangeRRdates_CheckinAfterCheckout', 'Error checkin is after checkout');
    Add('shTx_ChangeRRdates_BookingOverlap', 'WARNING : Bookings overlap ');
    Add('shTx_ChangeRRdates_PaidInvoicesReviewAfterChange', 'This reservation has paid invoices.' + #10 +
                                          'After changing dates - review prices');

     Add('shTx_ChangeRRdates_RoomDatesChangeAll', 'Not all room dates ' + #10 +
                                                  'comply with date of booking' + #10 +
                                                  '- Do you want to change them all ? ' + #10#10 +
                                                  'If you choose no the dates will change only' + #10 +
                                                  'for rooms that have a date booked');
    Add('shTx_ChangeRRdates_MustBe1Day', 'Number of dates must be atleast one day! - Check the Dates ! ');
    Add('shTx_StatisticsForecast_DataPreperation', 'Data preparation started');
    Add('shTx_StatisticsForecast_RoomResRetrieved', 'RoomReservation retrieved');
    Add('shTx_StatisticsForecast_RoomResUpdated', 'RoomReservation ResultData updated');
    Add('shTx_StatisticsForecast_GetUnBilled', 'Get unbilled goods ');
    Add('shTx_StatisticsForecast_UnbilledRerieved', 'Unbilled goods retrieved');
   // Add('shTx_ResGuestList_FileNotFound', 'Skráin %s fannst ekki ');
    Add('shTx_ResGuestList_FileNotFound', 'File %s not found ');
  //  Add('shTx_RptCustomer_FileNotFound', 'Skráin %s fannst ekki!');
    Add('shTx_RptCustomer_FileNotFound', 'File %s not found!');
    Add('shTx_RoomTypes_RoomTypeIsRequired', 'RoomType - is required - Use ESC to cancel');
    Add('shTx_RoomTypes_RoomTypeRequired', 'RoomType is required - set value or use [ESC] to cancel ');
    Add('shTx_RoomTypes_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_RoomTypes_ComingSoon', 'Coming Soon');
    Add('shTx_RoomTypes_EditInGrid', 'edit in grid');
    Add('shTx_SystemServers_UpdateOK', 'UPDATE OK');
    Add('shTx_SystemServers_DescriptionRequired', 'Descriprion is required - set value or use [ESC] to cancel ');
    Add('shTx_SystemServers_InsertNotOK', 'INSERT NOT OK');
    Add('shTx_SystemServers_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_SystemServers_EditInGrid', 'edit in grid');
    Add('shTx_SystemTriggers_UpdateNotOK', 'UPDATE NOT OK');
    Add('shTx_SystemTriggers_DescriptionRequired', 'Descriprion is required - set value or use [ESC] to cancel ');
    Add('shTx_SystemTriggers_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_SystemTriggers_InsertNotOK', 'INSERT NOT OK');
    Add('shTx_SystemTriggers_EditInGrid', 'edit in grid');
    Add('shTx_PayTypes_PayTypeCodeIsRequired', 'payType code - is required - Use ESC to cancel');
    Add('shTx_PayTypes_PayTypeRequired', 'Paytype Code required - set value or use [ESC] to cancel ');
    Add('shTx_PayTypes_PayGroupRequired', 'Paygroup Code required - set value or use [ESC] to cancel ');
    Add('shTx_PhoneRates_PhoneRateRequired', 'Phone rate Identification required - set value or use [ESC] to cancel ');
    Add('shTx_PayTypes_EditInGrid', 'edit in grid');

    Add('shTx_CountryGroups_CountryGroupsCodeIsRequired', 'CountryGroups code - is required - Use ESC to cancel');
    Add('shTx_CountryGroups_CountryGroupsRequired', 'CountryGroups Code required - set value or use [ESC] to cancel ');


    Add('shTx_ProvideARoom_RoomCheckedin', 'Room Status is: Guest Checked in.' + #13#13 + 'Do you want to move guest?');
    Add('shTx_ProvideARoom_RoomCheckedout', 'Room Status is: Guest has Checked out.' + #13#13 + 'Do you want to move guest?');
    Add('shTx_ProvideARoom_Hairdryer', 'hairdryer ');
    Add('shTx_ProvideARoom_Iron', 'iron ');
    Add('shTx_ProvideARoom_CoffeeMachines', 'coffee Machines ');
    Add('shTx_ProvideARoom_CoffeeMachine', 'coffee Machine ');
    Add('shTx_ProvideARoom_Fridges', 'fridges ');
    Add('shTx_ProvideARoom_Fridge', 'fridge ');
    Add('shTx_ProvideARoom_Minibars', 'minibars ');
    Add('shTx_ProvideARoom_Minibar', 'minibar ');
    Add('shTx_ProvideARoom_Kitchens', 'kitchens ');
    Add('shTx_ProvideARoom_Kitchen', 'kitchen ');
    Add('shTx_ProvideARoom_InternetPlugs', 'internet plugs ');
    Add('shTx_ProvideARoom_InternetPlug', 'internet p ');
    Add('shTx_ProvideARoom_Faxs', 'faxs ');
    Add('shTx_ProvideARoom_Fax', 'fax ');
    Add('shTx_ProvideARoom_Phone', 'phone ');
    Add('shTx_ProvideARoom_CDPlayer', 'CD Player ');
    Add('shTx_ProvideARoom_Radios', 'radios ');
    Add('shTx_ProvideARoom_Radio', 'radio ');
    Add('shTx_ProvideARoom_VCRs', 'VCRs ');
    Add('shTx_ProvideARoom_VCR', 'VCR ');
    Add('shTx_ProvideARoom_TVs', 'TVs ');
    Add('shTx_ProvideARoom_TV', 'TV ');
    Add('shTx_ProvideARoom_Safe', 'safe ');
    Add('shTx_ProvideARoom_Shower', 'shower ');
    Add('shTx_ProvideARoom_Baths', 'baths ');
    Add('shTx_ProvideARoom_Bath', 'bath ');
    Add('shTx_ProvideARoom_RoomWithout', 'Room without');
    Add('shTx_ProvideARoom_RoomWith', 'Room with');
  
    Add('shTx_StaffTypes2_UpdateNotOK', 'UPDATE NOT OK');
    Add('shTx_StaffTypes2_InsertNotOK', 'INSERT NOT OK');
    Add('shTx_StaffTypes2_StaffTypeRequired', 'StaffType is requierd - set value or use [ESC] to cancel ');
    Add('shTx_StaffTypes2_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_StaffTypes2_TypeIsRequired', 'Type - is required - Use ESC to cancel');
    Add('shTx_VATCodes_VATCode', 'VatCode');
    Add('shTx_VATCodes_UpdateNotOK', 'UPDATE NOT OK');
    Add('shTx_VATCodes_InsertNotOK', 'INSERT NOT OK');
    Add('shTx_VATCodes_VATCodeRequired', 'VatCode Code required - set value or use [ESC] to cancel ');
    Add('shTx_VATCodes_VATCodeCodeIsRequired', 'VatCode code is required - Use ESC to cancel');
    // Add('shTx_Seasons2_DescriptionRequired', 'Descriprion is required - set value or use [ESC] to cancel ');
    Add('shTx_Seasons2_DescriptionRequired', 'Description is required - set value or use [ESC] to cancel ');
    Add('shTx_Seasons2_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
    Add('shTx_Seasons2_EditInGrid', 'edit in grid');
    Add('shTx_PayGroups_PayGroup', 'Paygroup');
    Add('shTx_PayGroups_PayGroupRequired', 'PayGroup required - set value or use [ESC] to cancel ');
    Add('shTx_PayGroups_PayGroupCodeIsRequired', 'payGroup code - is required - Use ESC to cancel');
    Add('shTx_PhoneRates_PhoneRateCodeIsRequired', 'Phone rates Identification - is required - Use ESC to cancel');
    Add('shTx_PayGroups_EditInGrid', 'edit in grid');
    Add('shTx_RateRules_DescriptionRequired', 'Descriprion is required - set value or use [ESC] to cancel ');
    Add('shTx_RateRules_InsertNotOK', 'INSERT NOT OK');
    Add('shTx_RateRules_DescriptionIsRequired', 'Description - is required - Use ESC to cancel');
   // Add('shTx_Rooms_FilterActive', ' Sía virk!!! ');
    Add('shTx_Rooms_FilterActive', ' Filer Active!!! ');
   // Add('shTx_Rooms_Transactions', ' færslur af ');
      Add('shTx_Rooms_Transactions', ' Transactions ');
   // Add('shTx_Rooms_Visible', ' eru sýnilegar ');
      Add('shTx_Rooms_Visible', ' Visible ');
    Add('shTx_Rooms_DeleteRoom', 'Delete room "');
    Add('shTx_Rooms_Confirm', 'Confirm ?');
  end;
end;

procedure AddConstants_5;
begin
  with ConstantsDictionary do
  begin
    Add('shTx_RoomTypesEdit_NotFound', ' Not Found !!');
  (*  Add('shTx_RoomTypesEdit_RoomType', 'Herbergistegund ');
    Add('shTx_RoomTypesEdit_Available', ' er til');
    Add('shTx_RoomTypesEdit_Not2RoomTypes', 'Ekki er leyfilegt að hafa tvö herbergistegundir');
    Add('shTx_RoomTypesEdit_Same', 'með sama heiti');
    Add('shTx_RoomTypesEdit_DefineRoomType', 'Það verður að skilgreina herbergjaflokk');
    Add('shTx_RoomTypesEdit_DefineDescription', 'Það verður að skilgreina lýsingu herbergjaflokk');
    Add('shTx_RoomTypesEdit_DefinePrice', 'Það verður að skilgreina verðflokk herbergjaflokks');
    Add('shTx_RoomTypesEdit_DefineType', 'Það verður að skilgreina tegund herbergjaflokks');
    Add('shTx_RoomEdit_Room', 'herbergi ');
    Add('shTx_RoomEdit_Available', ' er til');
    Add('shTx_RoomEdit_No2Rooms', 'Ekki er leyfilegt að hafa tvö herbergi');
    Add('shTx_RoomEdit_SameNumber', 'með sama númeri');
    Add('shTx_RoomEdit_DefineRoomType', 'Það verður að skilgreina herbergjaflokk');
    Add('shTx_RoomEdit_DefineLocation', 'Það verður að skilgreina staðsetningu');
    Add('shTx_RoomEdit_Describe', 'Það verður að skrá lýsingu');
    Add('shTx_RoomEdit_NotFound', ' Finnst ekki !!');
    Add('shTx_RoomDateProblem_NotArrived', 'Ekki kominn');
    Add('shTx_RoomDateProblem_Guest', 'Gestur');
    Add('shTx_RoomDateProblem_Gone', 'Farinn');
    Add('shTx_RoomDateProblem_OverBooked', 'Yfirbókunn'); *)
  
    Add('shTx_RoomTypesEdit_RoomType', 'Room Type ');
    Add('shTx_RoomTypesEdit_Available', ' Available');
    Add('shTx_RoomTypesEdit_Not2RoomTypes', 'Cannot have two room types');
    Add('shTx_RoomTypesEdit_Same', 'with the same name');
    Add('shTx_RoomTypesEdit_DefineRoomType', 'Room type needs to be specified');
    Add('shTx_RoomTypesEdit_DefineDescription', 'Room types description must be specified');
    Add('shTx_RoomTypesEdit_DefinePrice', 'Room types price must be specified');
    Add('shTx_RoomTypesEdit_DefineType', 'Room Types class must be specified');
    Add('shTx_RoomEdit_Room', 'Room ');
    Add('shTx_RoomEdit_Available', ' Available');
    Add('shTx_RoomEdit_No2Rooms', 'Cannot have two rooms');
    Add('shTx_RoomEdit_SameNumber', 'with the same number');
    Add('shTx_RoomEdit_DefineRoomType', 'Room type needs to be specified');
    Add('shTx_RoomEdit_DefineLocation', 'Location needs to be specified');
    Add('shTx_RoomEdit_Describe', 'Description needed');
    Add('shTx_RoomEdit_NotFound', ' Not Found !!');
    Add('shTx_RoomDateProblem_NotArrived', 'Not Arrived');
    Add('shTx_RoomDateProblem_Guest', 'Guest');
    Add('shTx_RoomDateProblem_Gone', 'Gone');
    Add('shTx_RoomDateProblem_OverBooked', 'Over booked');
  
    Add('shTx_RoomDateProblem_NoShow', 'No Show');
    Add('shTx_RoomDateProblem_Allotment', 'Allotment');
    Add('shTx_StaffEdit2_InitialsRequired', 'Initials are required');
    Add('shTx_StaffEdit2_InitialExists', 'This already initial exists ');
    Add('shTx_StaffEdit2_NameRequired', 'Name is required');
    Add('shTx_StaffEdit2_RightsRequired', 'Set access rights of this staffmember');
    Add('shTx_StaffEdit2_LanguageRequired', 'Language is required');

   (* Add('shTx_ResProblem_NotArrived', 'Ekki kominn');
    Add('shTx_ResProblem_Guest', 'Gestur');
    Add('shTx_ResProblem_Gone', 'Farinn');
    Add('shTx_ResProblem_OverBooked', 'Yfirbókunn'); *)
  
    Add('shTx_ResProblem_NotArrived', 'Not Arrived');
    Add('shTx_ResProblem_Guest', 'guest');
    Add('shTx_ResProblem_Gone', 'gone');
    Add('shTx_ResProblem_OverBooked', 'Over booked');

    Add('shTx_ResProblem_NoShow', 'No Show');
    Add('shTx_ResProblem_Allotment', 'Allotment');
    Add('shTx_ResProblem_Blocked', 'Blocked');
    Add('shTx_uResMemos_MoveToHidden', 'Move to hidden :');
    Add('shTx_uResMemos_CopyToHidden', 'Copy to hidden :');
   // Add('shTx_TelPriceGroups_FilterActive', 'Sía virk!!! ');
    Add('shTx_TelPriceGroups_FilterActive', 'Filter Active!!! ');
    Add('shTx_TelPriceGroups_PhonePrice', 'Phonecall prices');
   // Add('shTx_TelPriceGroups_RegistrationFilter', 'Nýskráning er utan síu og sést því ekki');
    Add('shTx_TelPriceGroups_RegistrationFilter', 'Registration filtered and cannot be seen');
    Add('shTx_TelPriceGroups_DeletePricecode', 'Delete pricecode %s ?');
    Add('shTx_TelPriceRules_FilterActive', 'Filter Active!!! ');
    Add('shTx_TelPriceRules_PhonePrice', 'Phonecall prices');
    Add('shTx_TelPriceRules_RegistrationFilter', 'Registration filtered and cannot be seen');
    Add('shTx_TelPriceRules_DeletePricecode', 'Delete pricecode ?');
    Add('shTx_UDL_SelectServer', 'Select Server');
    Add('shTx_UDL_ServerAndDataBase', 'Select at least a Server and a Database!');
    Add('shTx_UDL_ConnectionSuccess', 'Connection successful!');


    Add('shTx_RoomTypesGroups_FilterActive', 'Filter Active!!! ');
    Add('shTx_RoomTypesGroups_Transactions', ' Transactions ');
    Add('shTx_RoomTypesGroups_Visible', ' Visible ');
    Add('shTx_RoomTypesGroups_RoomtypeGroups', 'Roomtype groups');
    Add('shTx_RoomTypesGroups_DeleteRoomtype', 'Delete Room Type ');
    Add('shTx_RoomTypesGroups_AreYouSure', 'Are You sure ??');
    Add('shTx_RoomTypes_FilterActive', ' Filter Active!!! ');
    Add('shTx_RoomTypes_Transactions', ' Transactions ');
    Add('shTx_RoomTypes_Roomtypes', 'Room types');
    Add('shTx_RoomTypes_DeleteRoomtype', 'Delete Room Type ');
    Add('shTx_RoomTypes_AreYouSure', 'Are You sure ??');
    Add('shTx_seasons_FilterActive', ' Filter Active!!! ');
    Add('shTx_seasons_Transactions', ' Transactions ');
    Add('shTx_seasons_Visible', ' Visible ');
    Add('shTx_seasons_PriceRange', 'Price Range');

    Add('shTx_TelPriceRulesEdit_Passed', 'Passed ');
    Add('shTx_TelPriceRulesEdit_NotValid', 'Not Valid');
    Add('shTx_TelPriceRulesEdit_CodeRequired', 'Code is required field');
    Add('shTx_TelPriceRulesEdit_PriceCodeExists', 'Price code exists - try again');
    Add('shTx_TelPriceRulesEdit_DescriptionRequired', 'Description is required field');
    Add('shTx_TelPriceRulesEdit_NotFound', ' Not found !');
    Add('shTx_AboutRoomer_CopyPMSVersion', 'Roomer PMS Version number has been copied to the clipboard');
    Add('shTx_AboutRoomer_NewVersionAvailable', 'There is a new version of ROOMER available (%s).' + #13 +
                                      'ROOMER needs to be updated.' + #13#13 +
                                      'Click [OK] to perform the update now.' + #13 +
                                      'Click [Cancel] to do this later');
    Add('shTx_AboutRoomer_NewVersionAvailableExpired', 'There is a new version of ROOMER available (%s).' + #13 +
                                      'You have already ignored the update %d times, but ROOMER needs to be immediately updated.' + #13#13 +
                                      'Click [OK] to start the update.');
    Add('shTx_AboutRoomer_NewVersionAvailableExpireWarning', 'There is a new version of ROOMER available (%s).' + #13 +
                                      'You have already ignored the update %d times! You will only get %d more possibilities to ignore.' + #13 +
                                      'After that ROOMER will stop working on the old version.' + #13#13 +
                                      'Click [OK] to start the update.' + #13 +
                                      'Click [Cancel] to update later');
    Add('shTx_Utils_EnterLogin', 'Please enter a login.');
    Add('shTx_Utils_MustEnterPassword', 'Password can''t be empty.You must enter a password.');
    Add('shTx_Utils_CannotClipboard', 'Cannot set clipboard');


    Add('shTx_PayTypesEdit_PayTypeAvailable', 'Pay Type Available - Try Again');
    Add('shTx_PayTypesEdit_DefinePayType', 'Pay Type needs to be specified');
    Add('shTx_PayTypesEdit_DefinePayGroup', 'Pay Type Payment catagory needs to be specified');
    Add('shTx_PayTypesEdit_NotFound', ' Not Found !!');
    Add('shTx_RoomTypesGroupsEdit_RoomType', 'Room Type ');
    Add('shTx_RoomTypesGroupsEdit_Available', ' Availble');
    Add('shTx_RoomTypesGroupsEdit_Not2RoomTypes', 'Cannot have two room types');
    Add('shTx_RoomTypesGroupsEdit_Same', 'with the same name');
    Add('shTx_RoomTypesGroupsEdit_DefineRoomTypeGroup', 'Room catagory must be specified');
    Add('shTx_RoomTypesGroupsEdit_DefineDescription', 'Room catagory Description must be specified');
    Add('shTx_PricesEdit_DateAvailable', 'Date is Available - Try Again');
    Add('shTx_PricesEdit_SpecifyDay', 'Day needs to be specified');
    Add('shTx_SeasonsEdit_DatesAvailable', 'Period with these dates is available - Try Again');
    Add('shTx_SeasonsEdit_SpecifySeason', 'Time Period needs to be specified');

    Add('shTx_TelPriceGroupsEdit_CodeRequired', 'Code is required field');
    Add('shTx_TelPriceGroupsEdit_PriceCodeExists', 'Price code exists - try again');
    Add('shTx_TelPriceGroupsEdit_DescriptionRequired', 'Description is required field');
    Add('shTx_RoomsNotFound_ComingSoon', 'Coming Soon');
  end;
end;

procedure AddConstants_CLang; // Baettu vid thennan ad vild
begin
  ConstantsDictionary.Add('dayStr1', 'Sunday;Monday;Tuesday;Wednesday;Thursday;Friday;Saturday');
end;

procedure AddConstants_SystemConstants;
var i : Integer;
begin
  with ConstantsDictionary do
  begin
    for i := 1 to 12 do
    begin
      Add('shSystem_Months_Short_' + inttostr(i), FormatSettings.ShortMonthNames[i]);
      Add('shSystem_Months_Long_' + inttostr(i), FormatSettings.LongMonthNames[i]);
    end;

    for i := 1 to 7 do
    begin
      Add('shSystem_Days_Short_' + inttostr(i), FormatSettings.ShortDayNames[i]);
      Add('shSystem_Days_Long_' + inttostr(i), FormatSettings.LongDayNames[i]);
    end;

    Add('shSystem_Date_Format_Long', FormatSettings.LongDateFormat);
    Add('shSystem_Date_Format_Short', FormatSettings.ShortDateFormat);

    Add('shSystem_Date_Separator', FormatSettings.DateSeparator);
    Add('shSystem_Time_Separator', FormatSettings.TimeSeparator);
  end;
end;

procedure AddConstants_NewUIConstants;
begin
  with ConstantsDictionary do
  begin
    Add('shUI_Check_In', 'Check in');
    Add('shUI_Check_Out', 'Check out');
    Add('shUI_Open_Invoice', 'Open invoice');
    Add('shUI_Reservation_Details', 'Reservation details');
    Add('shUI_Rate_Plan', 'Rate plan');
    Add('shUI_Notes', 'Notes');

    Add('shUI_Occupancy', 'Occupancy');
    Add('shUI_Availability', 'Availability');
    Add('shUI_RevPar', 'RevPar');
    Add('shUI_RoomRevenue', 'Room Revenue');
    Add('shUI_RoomsSold', 'Rooms sold');
    Add('shUI_BestAverageRate', 'BAR');
    Add('shUI_OOO', 'Out-of-order');
    Add('shUI_AverageDailyRate', 'ADR');

    Add('shUI_RoomRentInvoice', 'Room-rent Invoice : ');
    Add('shUI_RoomInvoices', 'Room Invoice : ');

    Add('shUI_CreditCardGuarantee', 'CREDIT-CARD GUARANTEE');
    Add('shUI_NoGuarantee', 'NO PAYMENT GUARANTEE');
    Add('shUI_DownpaymentGuarantee', 'USE DOWN-PAYMENTS');

    Add('shUI_NotAvailable', 'N/A');

    Add('shUI_InvoiceCaption', 'INVOICE');
    Add('shUI_CreditInvoiceCaption', 'CREDIT INVOICE');

    Add('shUI_ValueCopiedToClipboard', 'Value has been copied to clipboard.');
    Add('shUI_CheckInDialog', 'Show details dialog during check-in.');
    Add('shTx_CheckIn_PaymentGuarantee_Downpayment', 'Down payment as guarantee.');

    Add('shTx_ClearWindowsCacheAndClose', 'This will clear the statuses of the Roomer windows.'#10'After the clearing of the cache then Roomer will shut down.'#10'Afterwards, please start Roomer again.');

    Add('shUI_AmountOverAllowedWithdrawalLimit', 'Unable to add item to Invoice'#13'Total invoice exceeds the maximum withdrawal limit of this room');

    Add('shUI_GuestCouldNotBeFound', 'The guest could not be found.');

    Add('shUI_GuestDetailsDialog', 'Guest details');

    Add('shUI_NameCannotBeEmpty', 'Name cannot be empty');
    Add('shUI_NewReservationConfirmationEmail', 'New reservation confirmation');
    Add('shUI_CancelReservationConfirmationEmail', 'Cancelled reservation confirmation');

    Add('shTemplate_Room', 'Room');
    Add('shTemplate_Guests', 'Guests');
    Add('shTemplate_Price', 'Price');
    Add('shTemplate_Total', 'Total');
    Add('shTemplate_CCPayment', 'Payment');
    Add('shTemplate_Assurance', 'Payment');
    Add('shTemplate_PaymentFail', 'Failed');
    Add('shTemplate_PaymentSuccess', 'Successful');
    Add('shTemplate_TechnicalFailure', 'Technical failure');

    Add('shUI_Filename', 'Filename');
    Add('shUI_Subject', 'Subject');
    Add('shUI_User', 'User');
    Add('shUI_DateTime', 'Date/Time');
    Add('shUI_RenameFile', 'Rename');

    Add('shUI_BookKeepReortCustomerID', 'Customer Id');
    Add('shUI_BookKeepReortCustomerName', 'Customer Name');
    Add('shUI_BookKeepReortInvoice', 'Invoice');
    Add('shUI_BookKeepReortDate', 'Date');
    Add('shUI_BookKeepReortAccount', 'Account');
    Add('shUI_BookKeepReortDescription', 'Description');
    Add('shUI_BookKeepReortDebet', 'Debet');
    Add('shUI_BookKeepReortCredit', 'Credit');
    Add('shUI_BookKeepReortTotal', 'TOTAL:');
    Add('shUI_BookKeepReortSubtotal', 'Subtotal:');

    Add('shUI_Reports_DOWNPAYMENT', 'Down payment');
    Add('shUI_Reports_ÖÖSALE', 'Invoices');
    Add('shUI_Reports_PAYMENT', 'Payment');
    Add('shUI_Reports_ÖÖSALEITEMS', 'Item sales');

    Add('shUI_Reports_Action', 'Action');
    Add('shUI_Reports_Staff', 'Staff');
    Add('shUI_Reports_Invoice', 'Invoice');
    Add('shUI_Reports_Date', 'Date & time');
    Add('shUI_Reports_Room', 'Room');
    Add('shUI_Reports_BookingId', 'Booking Id');
    Add('shUI_Reports_ResId', 'Res Id');
    Add('shUI_Reports_Name', 'Name');
    Add('shUI_Reports_CustomerName', 'Customer');
    Add('shUI_Reports_GuestName', 'Guest');
    Add('shUI_Reports_Description', 'Description');
    Add('shUI_Reports_Total', 'Total');
    Add('shUI_Reports_PaymentType', 'Payment type');
    Add('shUI_Reports_MultipleRooms', '[Multiple rooms]');
    Add('shUI_Reports_CashInvoice', '[Cash Invoice]');
    Add('shUI_Reports_ALL', 'All');
    Add('shUI_Reports_CashierReportFor', 'Cashier Report for');
    Add('shUI_Reports_Balance', 'Balance');
    Add('shUI_Reports_SelectAtLeastOneUser', 'Please select at least 1 user.');
    Add('shUI_Reports_InvoicePayments', 'Invoice payments');
    Add('shUI_Reports_DownPayments', 'Down payments');

    Add('shUI_Reports_CashReport', 'Cash report');

    Add('shUI_Reports_InvoiceTypeCash', 'Cash');
    Add('shUI_Reports_InvoiceTypeGroup', 'Group');
    Add('shUI_Reports_InvoiceTypeRoom', 'Room');

    Add('shUI_Reports_CashierLineTypeSale', 'Closed invoices :');
    Add('shUI_Reports_CashierLineTypeSaleItems', 'Items sale :');
    Add('shUI_Reports_CashierLineTypeInvPayments', 'Invoice Payments :');
    Add('shUI_Reports_CashierLineTypeDownPayments', 'Down Payments :');

    Add('shUI_Reports_NoCashierReportsForThatDay', 'No cashier functions to report for this date.');

    Add('shUI_ChannelManager_AvailPublishWarning', 'Roomer will instantly publish these availability changes and send them to the channels in question.');
    Add('shUI_ChannelManager_RatesPublishWarning', 'Roomer will instantly publish these rate and/or restriction changes and send them to the channels in question.');
    Add('shUI_ChannelManager_OkOrCancel', 'Click [Ok] to continue, otherwise [Cancel]');

    Add('shUI_General_SELECT', 'Select');

    Add('shUI_Reports_UsersInReport', 'Users in report: ');
    Add('shUI_Reports_UserInReport', 'User in report: ');
    Add('shUI_Reports_ShiftInReport', 'Shift: ');

    Add('shUI_Checkout_GroupHeader', 'GROUP-INVOICE BALANCE (%d rooms)');
    Add('shUI_Checkout_RoomHeader', 'ROOM-INVOICE BALANCE (room %s)');
  end;
end;

procedure AddConstants_6; // Baettu vid thennan ad vild
begin
  with ConstantsDictionary do
  begin
    Add('shTx_RptResStat_NameForDatalayoutMissing', 'The layout name is required to continue');
    Add('shTx_GotoRoomAndDate_RefNotFound', 'Booking reference not found');
    Add('shDeleteChannelPlanCode', 'Delete channel plan code');
    Add('shTx_ChannelPlanCodes_UpdateNotOK', 'UPDATE NOT OK');
    Add('shTx_ChannelPlanCodes_InsertNotOK', 'INSERT NOT OK');
    Add('shTx_ChannelPlanCodes_CodeRequired', 'Code is required - set value or use [ESC] to cancel ');
    Add('shTx_ChannelPlanCodes_CodeIsRequired', 'Code is required - Use ESC to cancel');

    Add('shTx_ChannelAvailabilityManager_NoRoomTypeGroupsDefined', 'No Room Classes defined');
    Add('shTx_ChannelAvailabilityManager_NoChannelManagersDefined', 'No Channel managers defined');
    Add('shTx_ChannelAvailabilityManager_NoPlanCodesDefined', 'No Plan Codes defined');

    Add('shTx_ResEngine_Organization', 'Organization');

    Add('shTx_ChannelAvailabilityManager_ForceUpdateRates1', 'This will overwrite rates for all room classes for all dates!');
    Add('shTx_ChannelAvailabilityManager_ForceUpdateAvailability1', 'This will overwrite availability for all room classes for all dates!');
    Add('shTx_ChannelAvailabilityManager_ForceUpdate2', 'Normally it is enough to simply `Publish` the changes you make in this window.');
    Add('shTx_ChannelAvailabilityManager_ForceUpdate3', 'Are you sure you want to continue?');

    Add('shTx_FrmMain_OutOfOrder', 'OUT OF ORDER');

    Add('shTx_FrmMakeReservationQuick_OutOfOrderDescription', 'Description :');
    Add('shTx_FrmMakeReservationQuick_OutOfOrderStartDate', 'Start date :');
    Add('shTx_FrmMakeReservationQuick_OutOfOrderEndDate', 'End date :');

    Add('MainGuestConstant_Version_1', 'Main guest');
    Add('MainGuestConstant_Version_2', 'Guest name');
    Add('Dialog_Do_Not_Show_Again', 'Do not show this again');

    Add('shTx_FrmMain_ChannelAvailabilityClassesHintHeader', '<b><font color="#0000ff">AVAILABILITY</font></b><hr>');
    Add('shTx_FrmMain_StopSale', 'Stop');
    Add('shTx_FrmMain_StopSaleActiveOnOneOrMoreChannels', '<br><b><font color="#ff0000">STOP SALE</font></b> active on one or more channels.<br>');
    Add('shTx_FrmMain_RoomsAvailableFromChannels', '<b><font color="%s">%d</font></b> rooms<br>');
    Add('shTx_FrmMain_NoRoomsAvailableFromChannels', '<font color="#ff0000"><b>WARNING</b></font> <b>NO</b> rooms available for channels<br>');
    Add('shTx_FrmMain_RoomClassNotAvailableOnChannels', '<font color="#ff0000"><b>This room class is not shared on booking engines</b></font><br>');
    Add('shTx_FrmMain_AutoAvailabilityOnChannels', '<font color="#00ff00">Live updates on booking channels</font></b><br>');
    Add('shTx_FrmMain_WarningIncorrectAvailability', '<font color="#ff0000"><b>WARNING:</font><font color="#0000BB"> INCORRECT AVAILABILITY</font></b><br>');
    Add('shTx_FrmMain_ChannelMaxAvailability', '<b><font color="%s">%d</font></b> rooms maximum<br>');

    Add('shTx_FrmMain_ChannelMaxAvailUpdateFailed', 'Channel MAX availability update failed.');
    Add('shTx_FrmMain_ChannelChangedMaxAvail', 'Changed Max availabilty for %s on channels to %d');
    Add('shTx_FrmMain_WrongValueEntered', 'Wrong value entered');
    Add('shTx_FrmMain_ChannelAvailUpdateFailed', 'Channel availability update failed.');
    Add('shTx_FrmMain_ChannelChangedAvail', 'Availabilty for %s on channels set to %d');
    Add('shTx_FrmMain_GuestAndRoomNumberBeingMoved', 'Moving guest ''%s'' from room %s');

    Add('shTx_ChannelAvailabilityManager_RoomAvailabilityFetched', 'Availability is <font color="#ff0000"><b>being fetched</b></font>...');

    Add('shTx_FrmMain_CopiedReservationToClipboard', 'Reservation %d copied to the clipboard');
    Add('shTx_FrmMain_CopiedRoomReservationToClipboard', 'Reservation %d copied to the clipboard');
    Add('shTx_FrmMain_PastedReservationFromClipboard', 'Reservation %d has been pasted into the NO-ROOM area');
    Add('shTx_FrmMain_NoCopiedReservationFoundInClipboard', 'Reservation %d has been pasted into the NO-ROOM area');

    Add('shTx_FrmMain_ChannelRoomType', 'Channel roomtype');

    Add('shTx_FrmMain_UserCannotMoveTheRoomReservation', 'This room reservation has been blocked from moving - You are unable to move the guest to a different room.'#13#13 +
                 'If it is absolutely necessary to move this room reservation for a different room, then you will need to open'#13'the reservation profile and change the "Block Move" status to false.');


    Add('shTx_FrmChannelTogglingRules_ConfirmRemove', 'Do you really want to remove the selected rule: ');
    Add('shTx_FrmChannelTogglingRules_NewRule', '<New Rule>');
    Add('shTx_FrmChannelTogglingRules_Editing', 'Editing...');
    Add('shTx_FrmChannelTogglingRules_Viewing', 'Viewing...');

    Add('shTx_AllotmentToRes_InvalidAllotment', 'This is not a valid Allotment');

    Add('shTx_uInvoice_ItemWithIncorrectItemType', 'Item %s has a unknown Item Type: %s');
    Add('shTx_uInvoice_ItemTypeWithIncorrectVAT', 'Item type %s has a unknown VAT number: %s');

    Add('shTx_RoomResProfile_PackageAlreadyExists_Remove', 'This room already has a package assigned.' + #10 + 'Remove the package?');
    Add('shTx_RoomResProfile_NoPAckageForGroupInvoice', 'It is not possible to add a Package to a Group-invoice');

    Add('shTxProvideRoom_Short', 'Room');
    Add('shTxProvideRoom_Description', 'Description');
    Add('shTxProvideRoom_Type', 'Type');
    Add('shTxProvideRoom_TypeDescription', 'Type description');
    Add('shTxProvideRoom_NumRooms', 'Num');
    Add('shTxProvideRoom_Utilities', 'Utilities');
    Add('shTxProvideRoom_Location', 'Location');
    Add('shTxProvideRoom_Floor', 'Floor');

    Add('shTxProvideRoom_Bath', 'ba');    // Bath
    Add('shTxProvideRoom_Shower', 'Sh');    // Shower
    Add('shTxProvideRoom_Safe', 'Sf');    // Safe
    Add('shTxProvideRoom_Television', 'Tv');    // Television
    Add('shTxProvideRoom_Video', 'Vi');    // Video
    Add('shTxProvideRoom_Radio', 'Ra');    // Radio
    Add('shTxProvideRoom_CDPlayer', 'CD');    // CDPlayer
    Add('shTxProvideRoom_Telephone', 'Tp');    // Telephone
    Add('shTxProvideRoom_Fax', 'Fx');    // Fax
    Add('shTxProvideRoom_NetPlug', 'Ne');    // NetPlug
    Add('shTxProvideRoom_Kitchen', 'ki');    // Kitchen
    Add('shTxProvideRoom_Minibar', 'Mb');    // Minibar
    Add('shTxProvideRoom_Fridge', 'Fr');    // Fridge
    Add('shTxProvideRoom_Coffemachine', 'Co');    // Coffemachine
    Add('shTxProvideRoom_ClothingPress', 'Pr');    // ClothingPress
    Add('shTxProvideRoom_Hairdryer', 'Hd');    // Hairdryer
    Add('shTxProvideRoom_Status1', 'Status'); // Status1
    Add('shTxProvideRoom_Status', 'Status '); // Status

    Add('shTxInvoice_Form_Header_Item', 'Item');
    Add('shTxInvoice_Form_Header_Text', 'Text');
    Add('shTxInvoice_Form_Header_Number', 'Number');
    Add('shTxInvoice_Form_Header_UnitPrice', 'Unit Price');
    Add('shTxInvoice_Form_Header_Total', 'Total');
    Add('shTxInvoice_Form_Header_Reference', 'Reference');
    Add('shTxInvoice_Form_Header_Source', 'Source');
    Add('shTxInvoice_Form_Header_Package', 'Package');
    Add('shTxInvoice_Form_Header_Guests', 'Guests');
    Add('shTxInvoice_Form_Header_Confirmdate', 'Confirmdate');
    Add('shTxInvoice_Form_Header_ConfirmAmount', 'ConfirmAmount');
    Add('shTxInvoice_Form_Header_Vat', 'Vat');
    Add('shTxInvoice_Form_Header_Alias', 'Alias');

    Add('shTxLookAndFeel', 'Look && Feel');
    Add('shTx_Refresh_Local_Data_Cache', 'This will clear and refresh the local data-cache. Are you sure you want to continue?');

    Add('shTxEmailInvoice', 'Email invoice');

    Add('shTxReservationHasNoContactEmailAddress', 'Unable to send email confirmation.'#10'This reservation does not have any contact email address attached to it.');
    Add('shTxConfirmationEmailHasBeenSent', 'Booking confirmation email has been sent.');
    Add('shTxCancellationEmailHasBeenSent', 'Cancellation confirmation email has been sent.');

    Add('shTxExtraBedInvoiceText', 'Extra bed');

    Add('shTxThisConfirmAllottedBooking', 'This will change the full booking into a confirmed reservation.' + #10#10 +'Do you want to continue?');
  end;
end;

procedure AddConstants_7; // Baettu vid thennan ad vild
begin
  with ConstantsDictionary do
  begin
    Add('shTx_RptTurnoverPayments_ReportPerType', 'Report per product type');
    Add('shTx_RptTurnoverPayments_ReportPerItem', 'Report per product');
    Add('shTx_RptTurnoverPayments_NoConfirmedReports', 'No previously confirmed reports were selected.');

    Add('shTx_FrmMain_UnassignedItemsButton', 'Unassigned Rooms (%d)');

    Add('shTx_Various_DifferentRoomType', 'You are moving a booking of room type %s to a room of type %s.' + #10#10 +
                  'Are you sure you want to continue?');

    Add('shTx_Various_RoomNotClean', 'You are checking guest in to room %s which has not been cleaned.' + #10#10 +
                  'Are you sure you want to continue?');
    Add('shTx_Various_WouldCreateOverbooking', 'This would cause an overbooking for the following room type(s):' + #10#10);
    Add('shTx_Various_AreYoySureYouWantToContinue', 'Are you sure you want to continue?');

    Add('shTx_FinanceForecast_DoYouWantToConvertLayoutToNewVersion', 'The selected report is saved in an older format.' + #10 +
                  'Do you want to convert it to the new format now?' + #10#10 +
                  'Note: The report will not work correctly until you accept and convert the report to the newer format.' + #10 +
                  'After conversion though, the report will not work correctly in the older version of ROOMER PMS.');

    Add('shTx_Invoice_WarningWhenMovingCityTax',
                  'PLEASE NOTE:' + #13#13 +
                  'By moving the city-tax item to a different invoice you will disconnect it from the room-stay.' + #13 +
                  'This simply means that if you will later change the booking nights and/or prices then you' + #13 +
                  'will need to manually change the city-tax' + #13#13 +
                  'Do you want to continue anyway?');

    Add('shTx_frmReservationExtras_AddedMoreThenAvailableInPeriod',
                  'The Extra(s) [%s] do not have enough available stock for the whole reservation period: '+ #13 +
                  'Do you want to continue anyway?');
  end;
end;

procedure AddConstants_OfflineReports;
begin
  with ConstantsDictionary do
  begin
    Add(cshTx_OfflineReports_NameHeader, 'Report name');
    Add(cshTx_OfflineReports_DateGenHeader, 'Date Generated');
    Add(cshTx_OfflineReports_OfflineMessage,   'No connection with Roomer, working offline');

    Add(cshTx_HotelStatusOfflineReport_Name, 'Hotel Status Report');
    Add(cshTx_HotelArrivalsOfflineReport_Name, 'Hotel Arrivals Report');
  end;
end;

procedure prepareConstants;
begin
  ConstantsDictionary; // := TDictionary<String, String>.Create(TCustomEqualityComparer.Create());

  OriginalConstants;
  AddConstants_1;
  AddConstants_2;
  AddConstants_3;
  AddConstants_4;
  AddConstants_5;
  AddConstants_CLang;
  AddConstants_6;
  AddConstants_7;
  AddConstants_OfflineReports;

  AddConstants_SystemConstants;
  AddConstants_NewUIConstants;
end;

function GetTranslatedText(nameOfConstant : String) : String;
begin
  result := RoomerLanguage.GetTranslatedText(nameOfConstant);
end;

procedure GenerateTranslateTextTableForConstants;
var Key,
    rubbish : String;
begin
  RoomerLanguage.ActivateDBLanguageCollection;
  try
    for Key in ConstantsDictionary.Keys do
      rubbish := GetTranslatedText(Key);
    RoomerLanguage.SubmitDBLanguageCollection;
  finally
    RoomerLanguage.DeactivateDBLanguageCollection;
  end;
end;

procedure GenerateTranslateTextTableForAllForms;
begin
  frmProvideARoom2 := TfrmProvideARoom2.Create(nil); frmProvideARoom2.Free; frmProvideARoom2 := nil;
  frmMultiSelection := TfrmMultiSelection.Create(nil); frmMultiSelection.Free; frmMultiSelection := nil;
//  frmInvoiceInfo := TfrmInvoiceInfo.Create(nil); frmInvoiceInfo.Free; frmInvoiceInfo := nil;
  frmInvoice := TfrmInvoice.Create(nil); frmInvoice.Free; frmInvoice := nil;
  frmReservationProfile := TfrmReservationProfile.Create(nil); frmReservationProfile.Free; frmReservationProfile := nil;
//frmSplash := TfrmSplash.Create(nil); frmSplash.Free; frmSplash := nil;
  frmInvoicePayment := TfrmInvoicePayment.Create(nil); frmInvoicePayment.Free; frmInvoicePayment := nil;
  frmControlData := TfrmControlData.Create(nil); frmControlData.Free; frmControlData := nil;
  frmFinishedInvoices2 := TfrmFinishedInvoices2.Create(nil); frmFinishedInvoices2.Free; frmFinishedInvoices2 := nil;
  frmCreditPrompt := TfrmCreditPrompt.Create(nil); frmCreditPrompt.Free; frmCreditPrompt := nil;
//  frmInvoiceCompress := TfrmInvoiceCompress.Create(nil); frmInvoiceCompress.Free; frmInvoiceCompress := nil;
  frmInvoiceList := TfrmInvoiceList.Create(nil); frmInvoiceList.Free; frmInvoiceList := nil;
  frmConverts := TfrmConverts.Create(nil); frmConverts.Free; frmConverts := nil;
  frmSelLang := TfrmSelLang.Create(nil); frmSelLang.Free; frmSelLang := nil;
//frmUDL := TfrmUDL.Create(nil); frmUDL.Free; frmUDL := nil;
//frmHotelListMissing := TfrmHotelListMissing.Create(nil); frmHotelListMissing.Free; frmHotelListMissing := nil;
  frmMaidActions := TfrmMaidActions.Create(nil); frmMaidActions.Free; frmMaidActions := nil;
  frmMaidActionsEdit := TfrmMaidActionsEdit.Create(nil); frmMaidActionsEdit.Free; frmMaidActionsEdit := nil;
// Empty?  frmMakeReservation := TfrmMakeReservation.Create(nil); frmMakeReservation.Free; frmMakeReservation := nil;
  frmRoomDateProblem := TfrmRoomDateProblem.Create(nil); frmRoomDateProblem.Free; frmRoomDateProblem := nil;
  frmResProblem := TfrmResProblem.Create(nil); frmResProblem.Free; frmResProblem := nil;
//  frmStatisticsForcast := TfrmStatisticsForcast.Create(nil); frmStatisticsForcast.Free; frmStatisticsForcast := nil;
  frmDayFinical := TfrmDayFinical.Create(nil); frmDayFinical.Free; frmDayFinical := nil;
  frmConvertGroups := TfrmConvertGroups.Create(nil); frmConvertGroups.Free; frmConvertGroups := nil;
  frmInvoiceList2 := TfrmInvoiceList2.Create(nil); frmInvoiceList2.Free; frmInvoiceList2 := nil;
//  frmRptCustomer := TfrmRptCustomer.Create(nil); frmRptCustomer.Free; frmRptCustomer := nil;
//frmDayNotes := TfrmDayNotes.Create(nil); frmDayNotes.Free; frmDayNotes := nil;
  frmChangeRRdates := TfrmChangeRRdates.Create(nil); frmChangeRRdates.Free; frmChangeRRdates := nil;
  frmChangeRate := TfrmChangeRate.Create(nil); frmChangeRate.Free; frmChangeRate := nil;
  frmOpenInvoicesNew := TfrmOpenInvoicesNew.Create(nil); frmOpenInvoicesNew.Free; frmOpenInvoicesNew := nil;
  frmResMemos := TfrmResMemos.Create(nil); frmResMemos.Free; frmResMemos := nil;
//  frmSelHotel := TfrmSelHotel.Create(nil); frmSelHotel.Free; frmSelHotel := nil;
  frmHomedate := TfrmHomedate.Create(nil); frmHomedate.Free; frmHomedate := nil;
//  frmGoToRoomandDate := TfrmGoToRoomandDate.Create(nil); frmGoToRoomandDate.Free; frmGoToRoomandDate := nil;
  frmHiddenInfo := TfrmHiddenInfo.Create(nil); frmHiddenInfo.Free; frmHiddenInfo := nil;
  frmDownPayment := TfrmDownPayment.Create(nil); frmDownPayment.Free; frmDownPayment := nil;
  frmLodgingTaxReport2 := TfrmLodgingTaxReport2.Create(nil); frmLodgingTaxReport2.Free; frmLodgingTaxReport2 := nil;
  frmCancelReservation3 := TfrmCancelReservation3.Create(nil); frmCancelReservation3.Free; frmCancelReservation3 := nil;
  frmCancelReservation2 := TfrmCancelReservation2.Create(nil); frmCancelReservation2.Free; frmCancelReservation2 := nil;
  frmNationalReport3 := TfrmNationalReport3.Create(nil); frmNationalReport3.Free; frmNationalReport3 := nil;
  frmAddAccommodation := TfrmAddAccommodation.Create(nil); frmAddAccommodation.Free; frmAddAccommodation := nil;
  frmCountries := TfrmCountries.Create(nil); frmCountries.Free; frmCountries := nil;
  frmPayGroups := TfrmPayGroups.Create(nil); frmPayGroups.Free; frmPayGroups := nil;
  frmPriceCodes := TfrmPriceCodes.Create(nil); frmPriceCodes.Free; frmPriceCodes := nil;
  frmGuestProfile2 := TfrmGuestProfile2.Create(nil); frmGuestProfile2.Free; frmGuestProfile2 := nil;
  frmPayTypes := TfrmPayTypes.Create(nil); frmPayTypes.Free; frmPayTypes := nil;
  frmCountryGroups := TfrmCountryGroups.Create(nil); frmCountryGroups.Free; frmCountryGroups := nil;
  frmVatCodes := TfrmVatCodes.Create(nil); frmVatCodes.Free; frmVatCodes := nil;
  frmRebuildReservationStats := TfrmRebuildReservationStats.Create(nil); frmRebuildReservationStats.Free; frmRebuildReservationStats := nil;
  frmMakeReservationQuick := TfrmMakeReservationQuick.Create(nil); frmMakeReservationQuick.Free; frmMakeReservationQuick := nil;
  frmRoomerSplash := TfrmRoomerSplash.Create(nil); frmRoomerSplash.Free; frmRoomerSplash := nil;

  // No need for global variable
  //  frmRoomerLoginForm := TfrmRoomerLoginForm.Create(nil); frmRoomerLoginForm.Free; frmRoomerLoginForm := nil;
  TfrmRoomerLoginForm.Create(nil).Free;

  frmAboutRoomer := TfrmAboutRoomer.Create(nil); frmAboutRoomer.Free; frmAboutRoomer := nil;
  frmManageFilesOnServer := TfrmManageFilesOnServer.Create(nil); frmManageFilesOnServer.Free; frmManageFilesOnServer := nil;
  frmChannelAvailabilityManager := TfrmChannelAvailabilityManager.Create(nil); frmChannelAvailabilityManager.Free; frmChannelAvailabilityManager := nil;
  frmEditRoomPrice := TfrmEditRoomPrice.Create(nil); frmEditRoomPrice.Free; frmEditRoomPrice := nil;
  frmRoomCleanMaintenanceStatus := TfrmRoomCleanMaintenanceStatus.Create(nil); frmRoomCleanMaintenanceStatus.Free; frmRoomCleanMaintenanceStatus := nil;
  frmRates := TfrmRates.Create(nil); frmRates.Free; frmRates := nil;
  frmSeasons2 := TfrmSeasons2.Create(nil); frmSeasons2.Free; frmSeasons2 := nil;
  frmRoomRates := TfrmRoomRates.Create(nil); frmRoomRates.Free; frmRoomRates := nil;
  frmRoomTypesGroups2 := TfrmRoomTypesGroups2.Create(nil); frmRoomTypesGroups2.Free; frmRoomTypesGroups2 := nil;
  frmRoomTypes2 := TfrmRoomTypes2.Create(nil); frmRoomTypes2.Free; frmRoomTypes2 := nil;
  frmPackageItems := TfrmPackageItems.Create(nil); frmPackageItems.Free; frmPackageItems := nil;
  frmRooms3 := TfrmRooms3.Create(nil); frmRooms3.Free; frmRooms3 := nil;
  frmCustomers2 := TfrmCustomers2.Create(nil); frmCustomers2.Free; frmCustomers2 := nil;
  TfrmStaffEdit2.Create(nil).Free;
  frmStaffMembers2 := TfrmStaffMembers2.Create(nil); frmStaffMembers2.Free; frmStaffMembers2 := nil;
  frmCustomerEdit2 := TfrmCustomerEdit2.Create(nil); frmCustomerEdit2.Free; frmCustomerEdit2 := nil;
  frmChannels := TfrmChannels.Create(nil); frmChannels.Free; frmChannels := nil;
//  frmSystemTriggers := TfrmSystemTriggers.Create(nil); frmSystemTriggers.Free; frmSystemTriggers := nil;
//  frmCreatePassword := TfrmCreatePassword.Create(nil); frmCreatePassword.Free; frmCreatePassword := nil;
//  frmSystemServers := TfrmSystemServers.Create(nil); frmSystemServers.Free; frmSystemServers := nil;
//  frmSystemActions := TfrmSystemActions.Create(nil); frmSystemActions.Free; frmSystemActions := nil;
  frmStaffTypes2 := TfrmStaffTypes2.Create(nil); frmStaffTypes2.Free; frmStaffTypes2 := nil;
  TfrmItems2.Create(nil).Free;
  frmItemTypes2 := TfrmItemTypes2.Create(nil); frmItemTypes2.Free; frmItemTypes2 := nil;
  frmLocations := TfrmLocations.Create(nil); frmLocations.Free; frmLocations := nil;
  frmCurrencies := TfrmCurrencies.Create(nil); frmCurrencies.Free; frmCurrencies := nil;
//  frmInvoicePayment2 := TfrmInvoicePayment2.Create(nil); frmInvoicePayment2.Free; frmInvoicePayment2 := nil;
  frmChannelManager := TfrmChannelManager.Create(nil); frmChannelManager.Free; frmChannelManager := nil;
  frmCommunicationTest := TfrmCommunicationTest.Create(nil); frmCommunicationTest.Free; frmCommunicationTest := nil;
  frmHouseKeeping := TfrmHouseKeeping.Create(nil); frmHouseKeeping.Free; frmHouseKeeping := nil;
//  frmTableEditForm := TfrmTableEditForm.Create(nil); frmTableEditForm.Free; frmTableEditForm := nil;
  frmRptResStats := TfrmRptResStats.Create(nil); frmRptResStats.Free; frmRptResStats := nil;
  frmGuestSearch := TfrmGuestSearch.Create(nil); frmGuestSearch.Free; frmGuestSearch := nil;
//  frmRptResDates := TfrmRptResDates.Create(nil); frmRptResDates.Free; frmRptResDates := nil;
  frmChannelTogglingRules := TfrmChannelTogglingRules.Create(nil); frmChannelTogglingRules.Free; frmChannelTogglingRules := nil;
  frmAllotmentToRes := TfrmAllotmentToRes.Create(nil); frmAllotmentToRes.Free; frmAllotmentToRes := nil;
  frmPersonviptypes := TfrmPersonviptypes.Create(nil); frmPersonviptypes.Free; frmPersonviptypes := nil;
  frmPersonContactType := TfrmPersonContactType.Create(nil); frmPersonContactType.Free; frmPersonContactType := nil;
  frmKeyPairSelector := TfrmKeyPairSelector.Create(nil); frmKeyPairSelector.Free; frmKeyPairSelector := nil;
  frmResources := TfrmResources.Create(nil); frmResources.Free; frmResources := nil;
  frmAssignPayment := TfrmAssignPayment.Create(nil); frmAssignPayment.Free; frmAssignPayment := nil;
  frmRptDownPayments := TfrmRptDownPayments.Create(nil); frmRptDownPayments.Free; frmRptDownPayments := nil;
  frmTaxes := TfrmTaxes.Create(nil); frmTaxes.Free; frmTaxes := nil;

  TFrmMessagesTemplates.Create(nil).Free;

  FrmNotepad := TFrmNotepad.Create(nil); FrmNotepad.Free; FrmNotepad := nil;
  frmRptResInvoices := TfrmRptResInvoices.Create(nil); frmRptResInvoices.Free; frmRptResInvoices := nil;
  frmRptTotallist := TfrmRptTotallist.Create(nil); frmRptTotallist.Free; frmRptTotallist := nil;
  frmRptCustInvoices := TfrmRptCustInvoices.Create(nil); frmRptCustInvoices.Free; frmRptCustInvoices := nil;
  FrmRBEContainer := TFrmRBEContainer.Create(nil); FrmRBEContainer.Free; FrmRBEContainer := nil;
  frmRbePreferences := TfrmRbePreferences.Create(nil); frmRbePreferences.Free; frmRbePreferences := nil;
  frmRptManagment := TfrmRptManagment.Create(nil); frmRptManagment.Free; frmRptManagment := nil;

  FrmHandleBookKeepingException := TFrmHandleBookKeepingException.Create(nil); FrmHandleBookKeepingException.Free; FrmHandleBookKeepingException := nil;
  FrmRoomClassEdit := TFrmRoomClassEdit.Create(nil); FrmRoomClassEdit.Free; FrmRoomClassEdit := nil;

  frmRptReservations := TfrmRptReservations.Create(nil); frmRptReservations.Free; frmRptReservations := nil;
  FrmPostInvoices := TFrmPostInvoices.Create(nil); FrmPostInvoices.Free; FrmPostInvoices := nil;
  frmRptBreakfastGuests := TfrmRptBreakfastGuests.Create(nil); frmRptBreakfastGuests.Free; frmRptBreakfastGuests := nil;
  frmGuestCheckInForm := TfrmGuestCheckInForm.Create(nil); frmGuestCheckInForm.Free; frmGuestCheckInForm := nil;

  frmRptNotes := TfrmRptNotes.Create(nil); frmRptNotes.Free; frmRptNotes := nil;
//  frmRptGuests := TfrmRptGuests.Create(nil); frmRptGuests.Free; frmRptGuests := nil;
  frmRptReservationsCust := TfrmRptReservationsCust.Create(nil); frmRptReservationsCust.Free; frmRptReservationsCust := nil;

  frmGuestProfiles := TfrmGuestProfiles.Create(nil); frmGuestProfiles.Free; frmGuestProfiles := nil;
  frmGuestPortfolio := TfrmGuestPortfolio.Create(nil); frmGuestPortfolio.Free; frmGuestPortfolio := nil;


  frmRptTurnoverAndPayments := TfrmRptTurnoverAndPayments.Create(nil); frmRptTurnoverAndPayments.Free; frmRptTurnoverAndPayments := nil;
  frmRptResStatsRooms := TfrmRptResStatsRooms.Create(nil); frmRptResStatsRooms.Free; frmRptResStatsRooms := nil;

  frmEmailingDialog := TfrmEmailingDialog.Create(nil); frmEmailingDialog.Free; frmEmailingDialog := nil;

  frmMakeKreditInvoice := TfrmMakeKreditInvoice.Create(nil); frmMakeKreditInvoice.Free; frmMakeKreditInvoice := nil;

  frmBookKeepingCodes := TfrmBookKeepingCodes.Create(nil); frmBookKeepingCodes.Free; frmBookKeepingCodes := nil;

  FrmEditEmailProperties := TFrmEditEmailProperties.Create(nil); FrmEditEmailProperties.Free; FrmEditEmailProperties := nil;

  frmRptBookkeeping := TfrmRptBookkeeping.Create(nil); frmRptBookkeeping.Free; frmRptBookkeeping := nil;
  FrmReservationEmailingDialog := TFrmReservationEmailingDialog.Create(nil); FrmReservationEmailingDialog.Free; FrmReservationEmailingDialog := nil;
  FrmReservationCancellationDialog := TFrmReservationCancellationDialog.Create(nil); FrmReservationCancellationDialog.Free; FrmReservationCancellationDialog := nil;
  frmRptCashier := TfrmRptCashier.Create(nil); frmRptCashier.Free; frmRptCashier := nil;

  frmPhoneRates := TfrmPhoneRates.Create(nil); frmPhoneRates.Free; frmPhoneRates := nil;
  frmGroupGuests := TfrmGroupGuests.Create(nil); frmGroupGuests.Free; frmGroupGuests := nil;

  FrmEmailExcelSheet := TFrmEmailExcelSheet.Create(nil); FrmEmailExcelSheet.Free; FrmEmailExcelSheet := nil;

  frmRptTurnoverAndPayments := TfrmRptTurnoverAndPayments.Create(nil); frmRptTurnoverAndPayments.Free; frmRptTurnoverAndPayments := nil;
  FrmInvoiceLineEdit := TFrmInvoiceLineEdit.Create(nil); FrmInvoiceLineEdit.Free; FrmInvoiceLineEdit := nil;
  frmMergePortfolios := TfrmMergePortfolios.Create(nil); frmMergePortfolios.Free; frmMergePortfolios := nil;
  frmStaffComm := TfrmStaffComm.Create(nil); frmStaffComm.Free; frmStaffComm := nil;
  FrmCheckOut := TFrmCheckOut.Create(nil); FrmCheckOut.Free; FrmCheckOut := nil;
  FrmStaffNote := TFrmStaffNote.Create(nil); FrmStaffNote.Free; FrmStaffNote := nil;
  FrmMessageViewer := TFrmMessageViewer.Create(nil); FrmMessageViewer.Free; FrmMessageViewer := nil;
  frmInvoiceCompare := TfrmInvoiceCompare.Create(nil); frmInvoiceCompare.Free; frmInvoiceCompare := nil;
  FrmAlertEdit := TFrmAlertEdit.Create(nil); FrmAlertEdit.Free; FrmAlertEdit := nil;
  FrmAlertDialog := TFrmAlertDialog.Create(nil); FrmAlertDialog.Free; FrmAlertDialog := nil;
  FrmAlertPanel := TFrmAlertPanel.Create(nil); FrmAlertPanel.Free; FrmAlertPanel := nil;
  FrmCustomerDepartmentEdit := TFrmCustomerDepartmentEdit.Create(nil); FrmCustomerDepartmentEdit.Free; FrmCustomerDepartmentEdit := nil;

  FrmReservationHintHolder := TFrmReservationHintHolder.Create(nil);
  RoomerLanguage.TranslateThisForm(FrmReservationHintHolder);
  FrmReservationHintHolder.Free; FrmReservationHintHolder := nil;

  embOccupancyView := TembOccupancyView.Create(nil);
  RoomerLanguage.TranslateThisForm(embOccupancyView);
  embOccupancyView.Free; embOccupancyView := nil;

  embPeriodView := TembPeriodView.Create(nil);
  RoomerLanguage.TranslateThisForm(embPeriodView);
  embPeriodView.Free; embPeriodView := nil;

  FrmRateQuery := TFrmRateQuery.Create(nil);
  RoomerLanguage.TranslateThisForm(FrmRateQuery);
  FrmRateQuery.Free; FrmRateQuery := nil;

  TfrmOfflineReports.Create(nil).Free;

  TfrmArrivalsReport.Create(nil).Free;

  TFrmRoomReservationCancellationDialog.Create(nil).Free;
end;

initialization
  prepareConstants;

finalization

end.


