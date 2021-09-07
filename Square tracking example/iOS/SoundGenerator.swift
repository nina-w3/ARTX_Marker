//
//  Sound_Manager.swift
//  artoolkitX Square Tracking Example
//
//  Created by user on 25.08.21.
//  Copyright © 2021 artoolkit.org. All rights reserved.
//

import Foundation
import CoreAudioKit
import UIKit
import AudioKit

class SoundGenerator : NSObject
{
    var oscillators = [Synth]()
    final func setUp()
    {
        for i in 0 ..< Constants.numInstruments
        {
        let synth = Synth()
        AKOrchestra.addInstrument(synth)
        
        oscillators.append(synth)
        
        }
        AKOrchestra.start()
        for oscillator in oscillators
        {
            oscillator.play()
        }
    }
    final func playNoteOn(value: FrequencyAmplitudePair, channelNumber: Int)
    {
        let scaled Frequency = 0 + (value.frequency * Constants.frequencySale)
        oscillators[channelNumber].amplitude.setValue(value.amplitude / 4.0, forKey: "value")
        oscillators[channelNumber].frequency.setValue(scaledrequency, forKey: "value")
    }
}

class Synth: AKInstrument
{
    var frequency = AKInstrumentProperty(value: 0, minimum: 0, maximum: Constants.frequencyScale)
    var amplitude = AKInstrumentProperty(value: 0, minimum: 0, maximum: 0.25)
    override init()
    {
        super.init()
        
        let oscillator = AKOscillator()
        
        oscillator.frequency = frequency
        oscillator.amplitude = amplitude
        
        setAudioOutput(oscillator)
    }
}

