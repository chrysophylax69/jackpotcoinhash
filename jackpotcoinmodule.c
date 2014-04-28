#include <Python.h>

#include "jackpotcoin.h"

static PyObject *jackpotcoin_gethashpow(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    jackpotcoin_hash((char *)PyBytes_AsString((PyObject*) input), output, 0);
#else
    jackpotcoin_hash((char *)PyString_AsString((PyObject*) input), output, 0);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyObject *coin_gethashPoS(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    jackpotcoin_hash((char *)PyBytes_AsString((PyObject*) input), output, 1);
#else
    jackpotcoin_hash((char *)PyString_AsString((PyObject*) input), output, 1);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}


static PyMethodDef CoinMethods[] = {
    { "gethashpow", coin_getpowhash, METH_VARARGS, "Returns the proof of work hash" },
    { "gethashpos", coin_getposhash, METH_VARARGS, "Returns the proof of stake hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef CoinModule = {
    PyModuleDef_HEAD_INIT,
    "jackpotcoin_hash",
    "...",
    -1,
    CoinMethods
};

PyMODINIT_FUNC PyInit_coin_hash(void) {
    return PyModule_Create(&CoinModule);
}

#else

PyMODINIT_FUNC initcoin_hash(void) {
    (void) Py_InitModule("jackpotcoin_hash", CoinMethods);
}
#endif
