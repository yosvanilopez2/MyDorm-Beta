//
//  Listing.swift
//  MyDorm-Beta
//
//  Created by Yosvani Lopez on 12/10/16.
//  Copyright © 2016 Yosvani Lopez. All rights reserved.
//

import Foundation
import UIKit
import MapKit
enum StorageType: String {
    case InHouse = "In House"
    case Basement = "Basement"
    case OffLocation = "Off Location"
}

enum RentType: String {
    case Summer = "Summer"
    case Monthly = "Monthly"
    case Daily = "Daily"
}

 struct Listing {
    // maybe remove the question marks and make more secure
    var uid: String?
    var listingID: String?
    var location: String? // possibly change this to CLLocation
    var storageType = StorageType.InHouse
    var squareFeet: String?
    var rentType = RentType.Summer
    var rent: String?
    var dates: [Date]?
    var restrictedItems = [StorableObject]()
    var allowedItems = [StorableObject]()
    var images = [UIImage]()
    var description: String = ""
}
