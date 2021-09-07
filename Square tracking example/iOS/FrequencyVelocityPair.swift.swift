//
//  FrequencyVelocityPair.swift.swift
//  artoolkitX Square Tracking Example
//
//  Created by user on 25.08.21.
//  Copyright © 2021 artoolkit.org. All rights reserved.
//

import Foundation
import AudioKit
import UIKit

struct FrequencyAmplitudePair
{
    var frequency:Float
    var amplitude:Float
    
    init (frequency:Float, amplitude: Float)
    {
        self.frequency = frequency
        self.amplitude = amplitude
    }
    
}
