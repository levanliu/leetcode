def is_rhel7():
    return PLACEHOLDER_IS_RHEL7

def is_rhel9():
    return PLACEHOLDER_IS_RHEL9

def rhel_version():
    return '7' if PLACEHOLDER_IS_RHEL7 else '9'


# The next two settings are necessary only for the migration
# from PostgreSQL-9 (RHEL7) to PostgreSQL-13 (RHE9).

# On RHEL7 only: Do we have additional PostgreSQL-13 packages?
def has_postgresql13addon():
    return PLACEHOLDER_HAS_POSTGRESQL13ADDON

# On RHEL7 only: If additional postgresl-13 RPMs are installed,
# prefer them over the default RHEL7 postgresql-9 RPMs?
#
# customizable
PREFER_POSTGRESQL13 = False
