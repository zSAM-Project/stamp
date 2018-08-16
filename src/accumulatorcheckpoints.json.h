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
            "  },\n"
            "  {\n"
            "    \"height\": 32532,\n"
            "    \"1\": \"575ccf7c052b398673696c0c6e8801c8f32c1e2b764359c5fa72f4602dbb49ff5ec7901a3134f7482e4dafa197ae02a04fcd249effd9627dce5f3918e4d2f083a1c8769f0122e566ef9404d257fce48ad40082051e08ec7a216e7736d94ee70710d2b9b73d1eca683b66fb52bdacfd1b0a32ead2a8304beee023d66cc7e92ec600\",\n"
            "    \"5\": \"931ad26ad50f2d0f6a34d2fe9e6d108f33b6655aa688b052fec2481dd32c6f101e54ebad97dd4d18b167d21f41c004b82af7d6646917a54572636d0ff22e1952a713fb0048a213344b55ab30b22b9eac1de4584741d3f65bc51588a4b35c47268ca9a96338b4992bd1b0d85ecfeaf7561eb31bcabcbc0172d991d7e2aa259c8800\",\n"
            "    \"10\": \"99f83351d125df4e614f43aad24390e1288c75a033a3c448876c5ddea9c33e7a978e0d037abd659a0793f289c74c00db05f1e08cb893040c7215e001624d4334da0c4bfa7a53aeeecfb7994d146b06974457904b8c93e419be72393ab34c5131d06791e42d15dd2bec378a5d99ea0bb39772af6f0b3994d89ab0531f59c33466\",\n"
            "    \"50\": \"375853815025ecba2e28a29a03186928e16693d9286e9b79cd61f47bf39eec8f193ae6e0240934035512ff6774cd31781c4c8592611c820d571f89ef630924d42afc7a0fbe46891a5d5f47721ac5f39ee6e783a56ed32b33e6b4cf088d0c0d4d798c990885d3f5f00da6437b75a22e92a73b7b10f02fcbfa80c354bb21ba8ead00\",\n"
            "    \"100\": \"b3117c01f4da4d3486e4e3a624c496fd5339a34a7a00ccb45d99378ea58e461e8d2d9516eb1624607f0aa88c98295de0a161d3e5909df0bd67c15fd7a6d44c2e54fcca54f0c4d70b515b3724fd00f2b23f99629ea358f7bd7695cbe56c135d69c507d961467635f949bce1508ecc9518fea8c57fa84676531503d60f3b88c7ae00\",\n"
            "    \"500\": \"131e47219ddb6659f00234801b74a09e7085dc6921b1b16a4626d4a3cf49cbc7176706309baf2cb93bc49d8446f57166d47ac90c9d1519163e24dd63754096a70b172114fd4e2c42e07d74b4bd7a729e112644c015b6c654faf69ccbad8184249e47c24158ed7c7b9e7432c9cf64d218fe1bd6d35d3e0b080d0c18d5bbe236aa00\",\n"
            "    \"1000\": \"cdd2d1604ca1f7731ec7cb0d4b669a92e360a9601500fc69dde872603d7b38f82ca0cfeb8f84e0be0f1e67ba32cc7abed7440e56bfe8969ea3fc97131d554a9b011e666a766e79c33a28aa48ba491b4f6791b6fbca95cdd4b39d9be9a9dc23357faddfca774347252d885f3c8fb3a4474c1188bc1d2c08b79b9c1610817fcd3d\",\n"
            "    \"5000\": \"bbee0775cfa130eec33d3df47554f40d838798808a7247f83a91afb2591db5416a2c79301fa37d91a7e2ec13195fd5c924c85ff07ff4f8a9351b9c88412fc076715d296d31fcea9473970c4ed600b3e22ef7a407d1e842fae43c90efda18b6cf00e1baa2032ec74225482f94a9b1f4d9862417fa06efc487f20b49706dd8d8cb00\"\n"
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
