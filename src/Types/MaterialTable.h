//
// Created by neotron on 2018-01-07.
//

#pragma once
namespace Journal {
#define MAKEID(NAME) (QString(NAME).toLower().replace(" ", ""))
#define Encoded(NAME, RARITY, ABR, ID) { ID, Material(ID, NAME, ABR, Material::RARITY, Material::Encoded) }
#define Manufactured(NAME, RARITY, ABR) { MAKEID(NAME), Material(MAKEID(NAME), NAME, ABR, Material::RARITY, Material::Manufactured)}
#define ManufacturedA(NAME, RARITY, ABR, ID) { ID, Material(ID, NAME, ABR, Material::RARITY, Material::Manufactured)}
#define Raw(NAME, RARITY, ABR) { MAKEID(NAME), Material(MAKEID(NAME), NAME, ABR, Material::RARITY, Material::Raw)}

QMap<QString, Material> Materials::_materialTable =
    {
        // very common data
        Encoded("Anomalous Bulk Scan Data", VeryCommon, "ABSD", "bulkscandata"),
        Encoded("Atypical Disrupted Wake Echoes", VeryCommon, "ADWE", "disruptedwakeechoes"),
        Encoded("Distorted Shield Cycle Recordings", VeryCommon, "DSCR", "shieldcyclerecordings"),
        Encoded("Exceptional Scrambled Emission Data", VeryCommon, "ESED", "scrambledemissiondata"),
        Encoded("Specialised Legacy Firmware", VeryCommon, "SLF", "legacyfirmware"),
        Encoded("Unusual Encrypted Files", VeryCommon, "UEF", "encryptedfiles"),
        Encoded("Pattern Gamma Obelisk Data", VeryCommon, "PGOD", "ancienthistoricaldata"),
        // common data
        Encoded("Anomalous FSD Telemetry", Common, "AFT", "fsdtelemetry"),
        Encoded("Inconsistent Shield Soak Analysis", Common, "ISSA", "shieldsoakanalysis"),
        Encoded("Irregular Emission Data", Common, "IED", "archivedemissiondata"),
        Encoded("Modified Consumer Firmware", Common, "MCF", "consumerfirmware"),
        Encoded("Tagged Encryption Codes", Common, "TEC", "encryptioncodes"),
        Encoded("Unidentified Scan Archives", Common, "USA", "scanarchives"),
        Encoded("Pattern Beta Obelisk Data", Common, "PBOD", "ancientculturaldata"),
        // standard data
        Encoded("Classified Scan Databanks", Standard, "CSD", "scandatabanks"),
        Encoded("Cracked Industrial Firmware", Standard, "CIF", "industrialfirmware"),
        Encoded("Open Symmetric Keys", Standard, "OSK", "symmetrickeys"),
        Encoded("Strange Wake Solutions", Standard, "SWS", "wakesolutions"),
        Encoded("Unexpected Emission Data", Standard, "UED", "emissiondata"),
        Encoded("Untypical Shield Scans", Standard, "USS", "shielddensityreports"),
        Encoded("Abnormal Compact Emissions Data", Standard, "CED", "compactemissionsdata"),
        Encoded("Pattern Alpha Obelisk Data", Standard, "PAOD", "ancientbiologicaldata"),
        // rare data
        Encoded("Aberrant Shield Pattern Analysis", Rare, "ASPA", "shieldpatternanalysis"),
        Encoded("Atypical Encryption Archives", Rare, "AEA", "encryptionarchives"),
        Encoded("Decoded Emission Data", Rare, "DED", "decodedemissiondata"),
        Encoded("Divergent Scan Data", Rare, "DSD", "encodedscandata"),
        Encoded("Eccentric Hyperspace Trajectories", Rare, "EHT", "hyperspacetrajectories"),
        Encoded("Security Firmware Patch", Rare, "SFP", "securityfirmware"),
        Encoded("Pattern Delta Obelisk Data", Rare, "PDOD", "ancientlanguagedata"),
        // very rare data
        Encoded("Modified Embedded Firmware", VeryRare, "MEF", "embeddedfirmware"),
        Encoded("Classified Scan Fragment", VeryRare, "CSF", "classifiedscandata"),
        Encoded("Peculiar Shield Frequency Data", VeryRare, "PSFD", "shieldfrequencydata"),
        Encoded("Adaptive Encryptors Capture", VeryRare, "AEC", "adaptiveencryptors"),
        Encoded("Datamined Wake Exceptions", VeryRare, "DWE", "dataminedwake"),
        Encoded("Peculiar Shield Frequency Data", VeryRare, "PSFD", "shieldfrequencydata"),
        Encoded("Pattern Epsilon Obelisk Data", VeryRare, "PEOD", "ancienttechnologicaldata"),

        // very common manufactured
        Manufactured("Basic Conductors", VeryCommon, "BaC"),
        Manufactured("Chemical Storage Units", VeryCommon, "CSUn"),
        Manufactured("Compact Composites", VeryCommon, "CoCo"),
        Manufactured("Crystal Shards", VeryCommon, "CrSh"),
        Manufactured("Grid Resistors", VeryCommon, "GrRe"),
        Manufactured("Heat Conduction Wiring", VeryCommon, "HCWi"),
        Manufactured("Mechanical Scrap", VeryCommon, "MeSc"),
        Manufactured("Salvaged Alloys", VeryCommon, "SaAl"),
        Manufactured("Worn Shield Emitters", VeryCommon, "WSEm"),
        Manufactured("Thermic Alloys", VeryCommon, "ThAl"),
        // common manufactured
        Manufactured("Chemical Processors", Common, "ChPr"),
        Manufactured("Conductive Components", Common, "CoCo"),
        Manufactured("Filament Composites", Common, "FiCo"),
        ManufacturedA("Flawed Focus Crystals", Common, "FFCr", "uncutfocuscrystals"),
        Manufactured("Galvanising Alloys", Common, "GaAl"),
        Manufactured("Heat Dispersion Plate", Common, "HDPl"),
        Manufactured("Heat Resistant Ceramics", Common, "HRCe"),
        Manufactured("Hybrid Capacitors", Common, "HyCa"),
        Manufactured("Mechanical Equipment", Common, "MeEq"),
        Manufactured("Shield Emitters", Common, "ShEm"),
        // standard manufactured
        Manufactured("Chemical Distillery", Standard, "ChDi"),
        Manufactured("Conductive Ceramics", Standard, "CCoe"),
        Manufactured("Electrochemical Arrays", Standard, "ElAr"),
        Manufactured("Focus Crystals", Standard, "FoCr"),
        Manufactured("Heat Exchangers", Standard, "HeEx"),
        Manufactured("High Density Composites", Standard, "HDCo"),
        Manufactured("Mechanical Components", Standard, "MeCo"),
        Manufactured("Phase Alloys", Standard, "PhAl"),
        Manufactured("Precipitated Alloys", Standard, "PrAl"),
        Manufactured("Shielding Sensors", Standard, "ShSs"),
        // rare manufactured
        Manufactured("Chemical Manipulators", Rare, "ChMa"),
        Manufactured("Compound Shielding", Rare, "CoSh"),
        Manufactured("Conductive Polymers", Rare, "CoPo"),
        Manufactured("Configurable Components", Rare, "CCom"),
        Manufactured("Heat Vanes", Rare, "HeVa"),
        Manufactured("Polymer Capacitors", Rare, "PoCa"),
        Manufactured("Proto Light Alloys", Rare, "PLAl"),
        Manufactured("Refined Focus Crystals", Rare, "RFoC"),
        Manufactured("Tempered Alloys", Rare, "TeAl"),
        ManufacturedA("Proprietary Composites", Rare, "PrCo", "fedproprietarycomposites"),
        // very rare manufactured
        ManufacturedA("Core Dynamics Composites", VeryRare, "CDC", "fedcorecomposites"),
        Manufactured("Biotech Conductors", VeryRare, "BiC"),
        Manufactured("Exquisite Focus Crystals", VeryRare, "EFC"),
        Manufactured("Imperial Shielding", VeryRare, "ImSh"),
        Manufactured("Improvised Components", VeryRare, "ImCo"),
        Manufactured("Military Grade Alloys", VeryRare, "MGA"),
        Manufactured("Military Supercapacitors", VeryRare, "MSC"),
        Manufactured("Pharmaceutical Isolators", VeryRare, "PhIs"),
        Manufactured("Proto Heat Radiators", VeryRare, "PHeR"),
        Manufactured("Proto Radiolic Alloys", VeryRare, "PRaA"),

        // THARGOID MATERIALS
        ManufacturedA("Thargoid Carapace", Common, "TGCP", "unknowncarapace"),
        ManufacturedA("Thargoid Energy Cell", Standard, "TGEC", "unknownenergycell"),
        ManufacturedA("Thargoid Organic Circuitry", VeryRare, "TGOC", "unknownorganiccircuitry"),
        ManufacturedA("Thargoid Technology Components", Rare, "TGTC", "unknowntechnologycomponents"),
        ManufacturedA("Thargoid Sensor Fragment", VeryRare, "TGSF", "unknownenergysource"),
        ManufacturedA("Thargoid Wreckage Components", Standard, "TGWC", "tg_wreckagecomponents"),
        ManufacturedA("Thargoid Bio-Mechanical Conduits", Standard, "TGBMC", "tg_biomechanicalconduits"),
        ManufacturedA("Thargoid Weapon Parts", Rare, "TGWP", "tg_weaponparts"),
        ManufacturedA("Thargoid Propulsion Elements", VeryRare, "TGPE", "tg_propulsionelement"),

        // THARGOID DATA
        Encoded("Thargoid Material Composition Data", Standard, "TGMCD", "tg_compositiondata"),
        Encoded("Thargoid Structural Data", Common, "TGSD", "tg_structuraldata"),
        Encoded("Thargoid Residue Data", Rare, "TGRD", "tg_residuedata"),
        Encoded("Thargoid Ship Signature", Standard, "TGSS", "unknownshipsignature"),
        Encoded("Thargoid Wake Data", Rare, "TGWD", "unknownwakedata"),
        Encoded("Thargoid Ship Flight Data", Rare, "TGSFD", "tg_shipflightdata"),
        Encoded("Thargoid Ship System Data", Rare, "TGSSD", "tg_shipsystemsdata"),

        // Guardian data
        Encoded("Guardian Module Blueprint", VeryRare, "GMP", "guardian_moduleblueprint"),
        Encoded("Guardian Vessel Blueprint", Rare, "GVB", "guardian_vesselblueprint"),
        Encoded("Guardian Weapon Blueprint", Rare, "GWB", "guardian_weaponblueprint"),

        ManufacturedA("Guardian Power Cell", VeryCommon, "GPCe", "guardian_powercell"),
        ManufacturedA("Guardian Power Conduit", Common, "GPCo", "guardian_powerconduit"),
        ManufacturedA("Guardian Sentinel Weapon Parts", Standard, "GSWP", "guardian_sentinel_weaponparts"),
        ManufacturedA("Guardian Wreckage Components", VeryCommon, "GSWC", "guardian_sentinel_wreckagecomponents"),
        ManufacturedA("Guardian Tech Component", Standard, "GTC", "guardian_techcomponent"),

        // RAW VERY COMMON
        Raw("Carbon", VeryCommon, "C"),
        Raw("Iron", VeryCommon, "Fe"),
        Raw("Nickel", VeryCommon, "Ni"),
        Raw("Phosphorus", VeryCommon, "P"),
        Raw("Sulphur", VeryCommon, "S"),
        Raw("Rhenium", VeryCommon, "Re"),
        Raw("Lead", VeryCommon, "Pb"),

        // RAW COMMON
        Raw("Chromium", Common, "Cr"),
        Raw("Germanium", Common, "Ge"),
        Raw("Manganese", Common, "Mn"),
        Raw("Vanadium", Common, "V"),
        Raw("Zinc", Common, "Zn"),
        Raw("Zirconium", Common, "Zr"),
        Raw("Arsenic", Common, "As"),

        // RAW STANDARD
        Raw("Niobium", Standard, "Nb"),
        Raw("Tungsten", Standard, "W"),
        Raw("Cadmium", Standard, "Cd"),
        Raw("Boron", Standard, "B"),
        Raw("Mercury", Standard, "Hg"),
        Raw("Tin", Standard, "Sn"),
        Raw("Molybdenum", Standard, "Mo"),

        // RAW RARE
        Raw("Selenium", Rare, "Se"),
        Raw("Yttrium", Rare, "Y"),
        Raw("Antimony", Rare, "Sb"),
        Raw("Polonium", Rare, "Po"),
        Raw("Ruthenium", Rare, "Ru"),
        Raw("Technetium", Rare, "Tc"),
        Raw("Tellurium", Rare, "Te")

    };
}
