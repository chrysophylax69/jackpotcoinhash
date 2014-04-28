from distutils.core import setup, Extension

jackpotcoin_hash_module = Extension('jackpotcoin_hash',
                               sources = ['jackpotcoinmodule.c',
                                          'jackpotcoin.c',
										  'sha3/blake.c',
										  'sha3/groestl.c',
										  'sha3/jh.c',
										  'sha3/keccak.c',
										  'sha3/skein.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'jackpotcoin_hashs',
       version = '1.0',
       description = 'Bindings for proof of work/stake used by JackpotCoin',
       ext_modules = [jackpotcoin_hash_module])       
