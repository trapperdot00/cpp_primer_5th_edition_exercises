/*
 *	This header includes the Query class and all derived classes from Query_base
 *	Use this to simplify the includes
 */

#include "Query.h"		// This includes TextQuery, QueryResult, Query_base and WordQuery
#include "NotQuery.h"

// These both include BinaryQuery, but only does once
#include "AndQuery.h"
#include "OrQuery.h"
