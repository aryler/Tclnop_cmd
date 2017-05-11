/*
 * Copyright (c) 2017 Stuart Cassoff <stwo@users.sourceforge.net>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


/*
 * Tcl extension that provides a no-operation command.
 */


#ifdef __cplusplus
extern "C" {
#endif


#define MIN_TCL_VERSION "8.5"


#include <tcl.h>


static int Tnop_cmd_Nop_Cmd  (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[]);


/***/


static int
Tnop_cmd_Nop_Cmd (ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[]) {
	return TCL_OK;
}


/***/


static int
Tnop_cmd_PackageProvide (Tcl_Interp *interp) {
	return Tcl_PkgProvide(interp, PACKAGE_NAME, PACKAGE_VERSION);
}


static int
Tnop_cmd_PackageInit (Tcl_Interp *interp) {
	if (Tcl_CreateObjCommand(interp, "nop", Tnop_cmd_Nop_Cmd, NULL, NULL) == NULL) { return TCL_ERROR; }
	return TCL_OK;
}


static int
Tnop_cmd_CommonInit (Tcl_Interp *interp) {
	if (Tcl_InitStubs       (interp,        MIN_TCL_VERSION, 0) == NULL) { return TCL_ERROR; }
	if (Tcl_PkgRequire      (interp, "Tcl", MIN_TCL_VERSION, 0) == NULL) { return TCL_ERROR; }
	return TCL_OK;
}


EXTERN int
Tnop_cmd_Init (Tcl_Interp *interp) {
	if (Tnop_cmd_CommonInit     (interp) != TCL_OK) { return TCL_ERROR; }
	if (Tnop_cmd_PackageInit    (interp) != TCL_OK) { return TCL_ERROR; }
	if (Tnop_cmd_PackageProvide (interp) != TCL_OK) { return TCL_ERROR; }
	return TCL_OK;
}


EXTERN int
Tnop_cmd_SafeInit (Tcl_Interp *interp) {
	return Tnop_cmd_Init(interp);
}


#ifdef __cplusplus
}
#endif


/* EOF */
