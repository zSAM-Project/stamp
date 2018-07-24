// Copyright (c) 2018 The PIVX developers
// Copyright (c) 2018 The STAMP developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef STAMP_ACCUMULATORCHECKPOINTS_JSON_H
#define STAMP_ACCUMULATORCHECKPOINTS_JSON_H

#include <string>

std::string GetMainCheckpoints() {
    std::string strMainCheckpoints = "[\n"
            "  {\n"
            "    \"height\": 206,\n"
            "    \"1\": \"63a6eb2293ec99d0ebe80fc734373c8cb8d2bff6730db66248ac95eb700dd51a989c39075c2a6ded9c57bb3fc30c43e52c74d4f64535eb2892c61179b0be314edd0c6a0982b1f263f7970dad5dec87c61e1828396c4fd9a27761e3f23a1d7e27a6df66e8f2cbc1028d5a28d248886977ae00d035a5db938d353a25d7c380dfba00\",\n"
            "    \"5\": \"c5c8e2cd5bcf379604b3b6b7198baf8b03176403fede975056ca5793a0627ca0b12ff1c35f9b04611c9e935d8eb30a958332c2e9fe6dd8bca9aa7b5ae9f3704e42b0ad0978b44b751298a0921240374a7ae8ea0ad4bea47f1abafb2d68c24fc16a413a7cc60e648e2edf6ab6d12903679db2e4cbd49361ae2e82a936def5389a00\",\n"
            "    \"10\": \"777ee920944e546ba54e0e5d38764a4405db3d1201bec24db6b4d2388ceff7ddc0f208b7fe64d83b1201e0faec967bc50a984e8eefac59658ec8ff58f9f29c0c79baaed78731d882475fb7ca0b95ad5dc215a5b35e558328a4902743bf03444bc51ab3c5ab4ca439be14f5f8a5a130528bade6c8046cfb20c8267457e5bceb7c\",\n"
            "    \"50\": \"7fc477aafc5e4aacc0d1cc11ade54ad25a686f34bb8b8e85e5edd4f4c57b95fc263945052c978a871c0882a4a05665266cf15ae805dca1e523005f834975529482b7ce71cae07809d78323afec88d48cb8bfda6cd908684dc68f167c2639931d64f2bb496f4c804678ed58dc25f5ef85051f826bd87ed677c5078ac97b88d835\",\n"
            "    \"100\": \"1bb8810c1e558275030292feea95af7ef6946198c717ec153a01e9f757065245bee193b3d87fc40abd6a4ad67c188e52f1caf853bd7ee0af26cbe2f03e5aeef665f25f941985443c1776cdb27ae4b78b8af7d004434263bd92f80a6eac536ab59d84f3c65265a18b7f67d1b0395da59e19707c2e066b2622f7be6b65273001d400\",\n"
            "    \"500\": \"7915fea5ed6a63be04effcea0a95a9d9ce249debbd183a89d01d066971f44f8d324f56a40eb0e42b80a32b66661c3ab594d8fc56039d26532ff3ecde1a3d12ab3a99114acea4ed47389c5d01577876a879675032fca28b90456bec18852b7585318e07fecbb689a995a77738a8e441be438ff052ff37f09a77fc17770a97ba1b\",\n"
            "    \"1000\": \"a309e62c3fe8a5bd86b34604997ed071ae10e49ea86b526497d82313f38fc131b35b1e3b9f6fa469206c9ef742d9f78620fd2e224cae843d51bdf82b84e652fa56fc42cf317a2411f8b5dc338c6e79479e50eac726c7cdd10148405c4d509a32f303cb8f1aa8e50389207fec15f545bbf220f0a3ede02143cfbe9c66179cdede00\",\n"
            "    \"5000\": \"0f12151068fe147e354c3173d4c8b8957e09609f188a34aa2f52bef7ddb8d256c4910936828426575db3a26483c6a829741c4cf8a5971598c449980765c8d41ff3fbce626e216a7dec0f9a8bfabf821fd431f4ef3a0bd5a888add05b4d1c842b6c541f8cc28698e757c955f5f9f4d2becae280273fe25dfd80ef58281090e715\"\n"
            "  }\n"
            "]";
    return strMainCheckpoints;
}

std::string GetTestCheckpoints() {
    std::string strTestCheckpoints = "[\n"
            "  {\n"
            "    \"height\": 0,\n"
            "    \"1\": \"0\",\n"
            "    \"5\": \"0\",\n"
            "    \"10\": \"0\",\n"
            "    \"50\": \"0\",\n"
            "    \"100\": \"0\",\n"
            "    \"500\": \"0\",\n"
            "    \"1000\": \"0\",\n"
            "    \"5000\": \"0\"\n"
            "  }\n"
            "]";
    return strTestCheckpoints;
}

std::string GetRegTestCheckpoints() {
    std::string strRegTestCheckpoints = "[\n"
            "  {\n"
            "    \"height\": 0,\n"
            "    \"1\": \"0\",\n"
            "    \"5\": \"0\",\n"
            "    \"10\": \"0\",\n"
            "    \"50\": \"0\",\n"
            "    \"100\": \"0\",\n"
            "    \"500\": \"0\",\n"
            "    \"1000\": \"0\",\n"
            "    \"5000\": \"0\"\n"
            "  }\n"
            "]";
    return strRegTestCheckpoints;
}

#endif //STAMP_ACCUMULATORCHECKPOINTS_JSON_H
