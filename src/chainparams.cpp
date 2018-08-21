// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2018 The STAMP developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (    0, uint256("00000ce0e533e7ac0094536fab7fc57fc52589da9ec08d75a692e0e10e80f873"))
    (32591, uint256("ad9004160440c09ac4aef4584fbf4890bcc84676a0203a483d931517ca18619e"))
    (33270, uint256("9a69c6296c061777739451d8b003c14f4e6e029e9335e8607dd30642942a522b"))
    (33444, uint256("290feaadc6528e8c4fb72fd5f3444682781e247182f5fa5ef307db05ed68e570"))
    (33480, uint256("2bb916e6ff6465aa8450cf0e813db0f5967d6cc7655a31e0477f012b65d2eea7"))
    (33491, uint256("2f661e08d600a32b6dadca49a17a1a800abf4b4654c42982393315279e49068a"))
    (33798, uint256("b9df8209d5f4e37a8c8e7e4d43653e61f5237271d0aa6d47202a8c7d0abfc3c9"))
    (34000, uint256("2371d889de7c73a47768462babaf73c7bd4e4473b24518adade73d8725020114"))
    (34100, uint256("6454098739743e601b38ee6104e3862c47eeca0e3d10c1ae18ee85bb9c732ed4"))
    (34200, uint256("5e9df3a3d3ba899e8b23716f424f8010d9a588ab4a3aa0510634df1c177d8e10"))
    (34524, uint256("67eaf7886613a9c98be69a16a026c1723dca031a57987c72a6806ca7428eebbd"))
    (34850, uint256("a8872f25bdd616e304c8ef382c2936011f69421be83d9f89665da0556b075ae7"))
    (35000, uint256("8545bdbc4cece5667c6a4a2c0dbf4e8893dbb78554b99fe5f32b4bbfd92d3cd8"))
    (35100, uint256("b7ed56a9871c1de54fd4d226c9be4f8917e1faa22f537d57b67f90ee9722d200"))
    (35200, uint256("7357ff2a338d26ab4b4df51c4492dd298654963df5660d19689c788a4fddae5c"))
    (36162, uint256("17522c526307684c89a4d0fae2cfb2faf5c9d003284c3c852ddd85857a169a4f"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1534742991, // * UNIX timestamp of last checkpoint block
    74141,      // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1740710,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x2e;
        pchMessageStart[1] = 0x74;
        pchMessageStart[2] = 0x4c;
        pchMessageStart[3] = 0x38;
        vAlertPubKey = ParseHex("048c9563a2fd465f506948b2fb56f7c62b3d0ae8f8f70cd3679cff0a6b86b1b9832dac56959c1f61204cac89bc09716560a4a62a5707ae3e003348220db8ca77c4");
        nDefaultPort = 43451;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // STAMP starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // STAMP: 1 day
        nTargetSpacing = 1 * 60;  // STAMP: 1 minute
        nMaturity = 59;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 21000000 * COIN;

	nBlockStartTime = 1532408293;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 200;
        nModifierUpdateBlock = 0;
        nZerocoinStartHeight = nLastPOWBlock + 1;
        nZerocoinStartTime = nBlockStartTime + 3600; // after 1 hours
        nBlockEnforceSerialRange = nLastPOWBlock + 3; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = nLastPOWBlock + 4; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = nLastPOWBlock + 2; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = nLastPOWBlock + 4; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = nLastPOWBlock + 1; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0*COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 300; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1534773600; //!> Sporks signed after Monday, August 20, 2018 9:00:00 PM GMT+07:00 must use the new spork key
        nRejectOldSporkKey = 1534777200; //!> Fully reject old spork key after Monday, August 20, 2018 10:00:00 PM GMT+07:00

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "STAMP Coin will be in your pocket since 2018, by xNOOM";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04bdf00c60f49b72a773a4a955f7d74a71dbed0ee04be7aadd1974bc2c056b0614b10e5ac50c291369b950847e166814eb4a0887bb4abe43971b960ea3fd2ca3b1") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = nBlockStartTime;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 5918145;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000ce0e533e7ac0094536fab7fc57fc52589da9ec08d75a692e0e10e80f873"));
        assert(genesis.hashMerkleRoot == uint256("0xe9c29a65e7c07de3e05dcf7bb562949d443567f5c9300980195bd3f7a79374d9"));

	vSeeds.push_back(CDNSSeedData("stampcoin.club", "dnsseed1.stampcoin.club"));          // dnsseed1
	vSeeds.push_back(CDNSSeedData("seed1.stampcoin.club", "seed1.stampcoin.club"));       // Single node address

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 63);  // S
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 139); // x or y
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, (63+128));
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x04)(0x88).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "046bc97e47b4656ccd04d08dbf4ed3f3371c607bf968fe6cd0bf8494b3d8adaa526d0c94fd49806c6ef2bdb60f40216af5bf097709052a77b02b18ecf1f57fe60b";
        strSporkKeyOld = "04c5709a1c52ab478881e50343b147f8c00ef5b783d5cf4c68d50303b30dd6a0feed54475e593eb41aa48d08f14982df540357db87be0f479117b45abb9b0e7575";
        strObfuscationPoolDummyAddress = "SRyxzvDFrEhz3bdCrojKeao6y2WgiwUdJa";
        nStartMasternodePayments = nBlockStartTime + 7200; // after 2 hours

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zsam to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x42;
        pchMessageStart[1] = 0x75;
        pchMessageStart[2] = 0x64;
        pchMessageStart[3] = 0xb9;
        vAlertPubKey = ParseHex("041b5e37216743510bb3610dbb9e32c96fd3acdf961211e8a6b1347e7470ed1588ce52f4f5e171fbfb7bb1a5bf70a2714712c38f3a28b682d08deece44a23f737e");
        nDefaultPort = 43454;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // STAMP: 1 day
        nTargetSpacing = 1 * 60;  // STAMP: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 201576;
        nZerocoinStartTime = 1501776000;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 9891737; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 9891730; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 9902850; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 444020; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1532407972;
        genesis.nNonce = 6435794;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x000004020098a6730c686b6530d5dc9ba5d327dc2b75535b423818e7d4119ebf"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("stampcoin.club", "testnet.dnsseed.stampcoin.club"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 125); // Testnet stampcoin addresses start with 's'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet stamp script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet stamp BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet stamp BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet stamp BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "044356033dd4b5d18880791c4b1c21426d2c2a783e7052893e7aba3afa0f0d58145ed276333bd57659f6493bef37a0fb865c81d8415091edacb34f4ea763e83698";
        strSporkKeyOld = "04ed098b555a7afde2e017926db19412235f91924114e429d62e1c5beb7e531af0ce3e26e46c9182e0fa551715d57ea2ab0793d134490e4f681417dbc33c0532e5";
        strObfuscationPoolDummyAddress = "sVDjhvCE5MoWWddpy4XncSojB6gxRTkARY";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x68;
        pchMessageStart[1] = 0xce;
        pchMessageStart[2] = 0x7c;
        pchMessageStart[3] = 0xab;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // STAMP: 1 day
        nTargetSpacing = 1 * 60;        // STAMP: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1532404397;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 5827680;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 43456;
        //assert(hashGenesisBlock == uint256("0x000003a40a25ba3789033a7480d31e6081e32ef5dee94c0c3a71e3f719c68a03"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 43458;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
